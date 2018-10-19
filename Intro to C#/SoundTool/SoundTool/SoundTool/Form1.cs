using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Input;
using NAudio.Wave;
using NAudio.Midi;


namespace SoundTool
{
    public partial class Form1 : Form
    {
        bool isMIDIRecording = false;

        //class to hold path name, and filename (to use as a display name)
        public class FileDataStrings
        {
            public FileDataStrings(string path) { fullPath = path; displayName = Path.GetFileName(path); }
            public string fullPath      { get; set; }
            public string displayName { get; set; }
        }

        public class SamplerData
        {
            public SamplerData(TextBox txt, Button btn, Label lbl)
            {
                pathInfo = null;
                triggerMode = true;
                keyDown = false;
                txt_name = txt;
                btn_name = btn;
                lbl_name = lbl;
                updateToggleText();
            }
            FileDataStrings pathInfo;                       //path information
            bool triggerMode;                               //TriggerMode - true = Trigger Mode enabled; false = Gate Mode Enabled
            bool currentlyPlaying;                          
            bool keyDown;
            

            //Holds Associated Design items
            TextBox txt_name;
            Button btn_name;
            Label lbl_name;

            private IWavePlayer wavePlayer;
            private WaveOut waveOut;
            private AudioFileReader audioFileReader;

            void updateToggleText ()
            {
                if (triggerMode) { btn_name.Text = "Trigger"; }
                else             { btn_name.Text = "Gate"; }
            }

            void updateTextBox()
            {
               if (pathInfo.displayName != null)
                {
                    txt_name.Text = pathInfo.displayName;
                }

            }

            void refresh ()
            {
                currentlyPlaying = false;

                wavePlayer = null;
                waveOut = null;
                audioFileReader = null;
            }

            //Debugging method
            public void stopNow ()
            {
                stopPlayback();
                currentlyPlaying = false;
            }

            public void toggleClicked ()
            {
                triggerMode = !triggerMode;
                updateToggleText();
                refresh();
            }
            //Class function called when a file is dragged in
            public void fileDraggedin (string file)
            {
                pathInfo = new FileDataStrings(file);
                updateTextBox();
            }
            private IWavePlayer CreateWavePlayer()
            {
                return new WaveOut();
            }

            //Class function used if the associated key is pressed
            public void pressKey ()
            {
                lbl_name.ForeColor = System.Drawing.Color.LimeGreen;
                if (!keyDown)
                {
                     if (triggerMode && pathInfo != null)
                        {
                            if (currentlyPlaying)
                            {
                                stopPlayback();
                                refresh();
                            }
                            startPlayback();
                            currentlyPlaying = true;
                        }
                        else if (!triggerMode && pathInfo != null)
                        {
                            startPlayback();
                            currentlyPlaying = true;
                        }
                        keyDown = true;
                }
            }

            //Class function used if the associated key is released
            public void releaseKey ()
            {
                keyDown = false;
                lbl_name.ForeColor = System.Drawing.Color.Black;
                if (pathInfo != null && waveOut != null)
                {
                    if (triggerMode && waveOut.PlaybackState == PlaybackState.Stopped)
                    {
                        stopPlayback();
                        refresh();
                    }
                    if (!triggerMode)
                    {
                        stopPlayback();
                        refresh();
                        currentlyPlaying = false;
                    }
                }
            }



            private void startPlayback()
            {
                    if (waveOut == null && !triggerMode)
                    {
                        wavePlayer = CreateWavePlayer();
                        WaveFileReader reader = new WaveFileReader(pathInfo.fullPath);
                        LoopStream loop = new LoopStream(reader);
                        waveOut = new WaveOut();
                        waveOut.Init(loop);
                        waveOut.Play();
                    }
                    else if (waveOut == null && triggerMode)
                    {
                        wavePlayer = CreateWavePlayer();
                        audioFileReader = new AudioFileReader(pathInfo.fullPath);
                        wavePlayer.Init(audioFileReader);
                        waveOut = new WaveOut();
                        waveOut.Init(audioFileReader);
                        waveOut.Play();
                        waveOut.PlaybackStopped += new EventHandler<StoppedEventArgs>(delegate (object sender, StoppedEventArgs e)
                        {
                            stopPlayback();
                        });
                    }
            }
            void stopPlayback()
            {
                if (pathInfo != null)
                {
                    waveOut.Stop();
                    waveOut.Dispose();
                    waveOut = null;
                    currentlyPlaying = false;
                }
                TidyUp();
            }

            void TidyUp()
            {
                if (audioFileReader != null)
                {
                    audioFileReader.Dispose();
                    audioFileReader = null;
                }
                if (wavePlayer != null)
                {
                    wavePlayer.Dispose();
                    wavePlayer = null;
                }
                if (waveOut != null)
                {
                    waveOut.Dispose();
                    waveOut = null;
                }
            }
        };

        Dictionary<int, SamplerData> m_samples = new Dictionary<int, SamplerData>();
        


        //Setting up
        public Form1()
        {
            InitializeComponent();

            TextBox[] txt_list = new TextBox[9] { txt_KP1file, txt_KP2file, txt_KP3file,
            txt_KP4file, txt_KP5file, txt_KP6file, txt_KP7file, txt_KP8file, txt_KP9file};

            Button[] btn_list = new Button[9] { btn_KP1Toggle, btn_KP2Toggle, btn_KP3Toggle,
            btn_KP4Toggle, btn_KP5Toggle, btn_KP6Toggle, btn_KP7Toggle, btn_KP8Toggle, btn_KP9Toggle};

            Label[] lbl_list = new Label[9] { lbl_KP1, lbl_KP2, lbl_KP3, lbl_KP4, lbl_KP5,
            lbl_KP6, lbl_KP7, lbl_KP8, lbl_KP9};

            for (int i = 1; i <= 9; i++)
            {
                m_samples.Add(i, new SamplerData(txt_list[i-1], btn_list[i-1], lbl_list[i-1]));
            }            
        }

        //Functions that add sameples to list (using open dialogue box)
        private void btn_addsamples_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog openFileDialog = new OpenFileDialog())
            {
                openFileDialog.Filter = "Audio Files(*.wav;*.mp3)|*.wav;*.mp3";
                openFileDialog.RestoreDirectory = true;
                openFileDialog.Multiselect = true;
                if (openFileDialog.ShowDialog() == DialogResult.OK)
                {
                    foreach (string file in openFileDialog.FileNames)
                    {
                        lst_samplelist.Items.Add(file);
                    }
                }
            }
        }
        //Functions that add sameples to list (using drag and drop from external files)
        private void lst_samplelist_DragEnter(object sender, DragEventArgs e)
        {
            string[] fileNames = (string[])e.Data.GetData(DataFormats.FileDrop, false);
            if (fileNames != null)
            {
                foreach (string file in fileNames)
                {
                    lst_samplelist.Items.Add(file);
                }
            }

            //e.Effect = DragDropEffects.All;
        }

        //Detects if a Key is pressed, if one that is pressed is usuable by a sampler, it calls a "pressKey" function on that instance of Sampler Data
        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            char key = Convert.ToChar(e.KeyCode);
            if (key > 96 && key < 106)
            {
                m_samples[key - 96].pressKey();
            }
            else if (key == 35)
            {
                for (int i = 1; i <= 9; ++i)
                {
                    m_samples[i].stopNow();
                }
            }
        }
        //Detects if a Key is released, if one that is released is usuable by a sampler, it calls a "releaseKey" function on that instance of Sampler Data
        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            char key = Convert.ToChar(e.KeyCode);
            if (key > 96 && key < 106)
            {
                m_samples[key - 96].releaseKey();
            }
        }


        //Detects if Trigger/Gate Toggle button is clicked, and calls the 
        private void btn_Toggle_Click(object sender, EventArgs e)
        {
            Button b = (Button)sender;
            string name = b.Name;
            int id = int.Parse(name.Substring(6, 1));
            m_samples[id].toggleClicked();
        }

        private void txt_samplefile_DragDrop(object sender, DragEventArgs e)
        {
            TextBox t = (TextBox)sender;
            string name = t.Name;
            int id = int.Parse(name.Substring(6, 1));
            string fileName = (string)e.Data.GetData(DataFormats.StringFormat, false);
            m_samples[id].fileDraggedin(fileName);
        }

        private void txt_samplefile_DragEnter(object sender, DragEventArgs e)
        {
            e.Effect = DragDropEffects.All;
            //TextBox t = (TextBox)sender;
            //string name = t.Name;
            //int id = int.Parse(name.Substring(6, 1));
            //string fileName = (string)e.Data.GetData(DataFormats.FileDrop, false);
            //m_samples[id].fileDraggedin(fileName);
        }

        private void lst_samplelist_MouseDown(object sender, MouseEventArgs e)
        {
            if (lst_samplelist.SelectedItem != null) { lst_samplelist.DoDragDrop(lst_samplelist.SelectedItem, DragDropEffects.Copy); }
        }

        private void waveViewer_DragDrop(object sender, DragEventArgs e)
        {
            string fileName = (string)e.Data.GetData(DataFormats.Text);

            waveViewer.SamplesPerPixel = 1200;
            waveViewer.WaveStream = new NAudio.Wave.WaveFileReader(fileName);
        }


        private void cmb_InputsList_Click(object sender, EventArgs e)
        {
            List<NAudio.Wave.WaveInCapabilities> activeInputs = new List<NAudio.Wave.WaveInCapabilities>();

            for (int i = 0; i < NAudio.Wave.WaveIn.DeviceCount; ++i)
            {
                activeInputs.Add(NAudio.Wave.WaveIn.GetCapabilities(i));
            }

            cmb_InputsList.Items.Clear();

            foreach (var device in activeInputs)
            {
                string item = (device.ProductName).ToString();
                cmb_InputsList.Items.Add(item);
            }
        }

        private NAudio.Wave.WaveIn InputStream = null;
        private NAudio.Wave.DirectSoundOut DirectOut = null;
        bool isRecording = false;
        NAudio.Wave.WaveFileWriter waveWriter = null;


        private void btn_RECSTOP_Click(object sender, EventArgs e)
        {
            if (!isRecording)
            {
                 if (cmb_InputsList.SelectedItem == null)
                 {
                     MessageBox.Show("Error! \n No Input Selected, Please select an Audio Input before recording");
                     return;
                 }

                SaveFileDialog save = new SaveFileDialog();
                save.Filter = "Wave File(*.wav)|*.wav;";
                if (save.ShowDialog() != System.Windows.Forms.DialogResult.OK)
                {
                    return;
                }
                else
                {
                    lst_samplelist.Items.Add(save.FileName);
                }

                int deviceNumber = cmb_InputsList.SelectedIndex;

                InputStream = new NAudio.Wave.WaveIn();
                InputStream.DeviceNumber = deviceNumber;
                InputStream.WaveFormat = new NAudio.Wave.WaveFormat(44100, NAudio.Wave.WaveIn.GetCapabilities(deviceNumber).Channels);

                InputStream.DataAvailable += new EventHandler<NAudio.Wave.WaveInEventArgs>(InputStream_DataAvailable);
                waveWriter = new NAudio.Wave.WaveFileWriter(save.FileName, InputStream.WaveFormat);

                InputStream.StartRecording();

                btn_RECSTOP.Text = "STOP";
                isRecording = true;
            }
            else
            {
                if (InputStream != null)
                {
                    InputStream.StopRecording();
                    InputStream.Dispose();
                    InputStream = null;
                }
                if (waveWriter != null)
                {
                    waveWriter.Dispose();
                    waveWriter = null;
                }
                btn_RECSTOP.Text = "REC";
                isRecording = false;
            }
           
        }

        private void InputStream_DataAvailable(object sender, NAudio.Wave.WaveInEventArgs e)
        {
            if (waveWriter == null) return;

            waveWriter.Write(e.Buffer, 0, e.BytesRecorded);
            waveWriter.Flush();
        }


        
        Dictionary<TimeSpan, int> m_MidiData = new Dictionary<TimeSpan, int>();
        //private void btn_MIDI_RECSTOP_Click(object sender, EventArgs e)
        //{
        //    System.Diagnostics.Stopwatch stopwatch = System.Diagnostics.Stopwatch.StartNew();
        //    if (!isMIDIRecording)
        //    {
        //        btn_MIDI_RECSTOP.Text = "STOP";
        //        isMIDIRecording = true;

        //        SaveFileDialog save = new SaveFileDialog();
        //        save.InitialDirectory = @"C:\Users\s182378\Documents\Code\repositories\AIE2018\Intro to C#\SoundTool\SoundTool\MIDIFiles";
        //        save.Filter = "Text File *.txt|*.txt;";
        //        if (save.ShowDialog() != System.Windows.Forms.DialogResult.OK)
        //        {
        //            return;
        //        }

        //        KeyEventArgs Ke = new KeyEventArgs(new Keys());

        //        char key = Convert.ToChar(Ke.KeyCode);
        //        if (key > 96 && key < 106)
        //        {
        //            m_MidiData.Add(stopwatch.Elapsed, (key - 96));
        //        }

        //    }
        //    else
        //    {
        //        stopwatch.Stop();
        //        m_MidiData.Add(stopwatch.Elapsed, 285);
        //        List<string> MIDIstring = new List<string>();
        //        foreach (KeyValuePair<TimeSpan, int> entry in m_MidiData)
        //        {
        //            string MIDIstring_entry = entry.Key + " " + entry.Value;
        //            MIDIstring.Add(MIDIstring_entry);
        //        }
        //        MIDIstring.ToArray();

        //        System.IO.File.WriteAllLines("scores.txt", MIDIstring);
        //        btn_MIDI_RECSTOP.Text = "REC";
        //        isMIDIRecording = false;
        //    }

        //}

        private void btn_MIDI_RECSTOP_Click(object sender, EventArgs e)
        {
            if (!isMIDIRecording)
            {
               //MidiIn(deviceNumber) how do I find device number
            }

            else
            {
               
            }

        }



        private void cmb_MIDI_FileList_Click(object sender, EventArgs e)
        {
            List<string> MIDIs = new List<string>();

            DirectoryInfo dir = new DirectoryInfo(@"C:\Users\s182378\Documents\Code\repositories\AIE2018\Intro to C#\SoundTool\SoundTool\MIDIFiles");
            FileInfo[] Files = dir.GetFiles();

            cmb_MIDI_FileList.Items.Clear();

            foreach(FileInfo file in Files)
            {
                cmb_MIDI_FileList.Items.Add(file);
            }
        }

        private void cmb_MIDI_InList_Click(object sender, EventArgs e)
        {
            for (int device = 0; device < MidiIn.NumberOfDevices; device++)
            {
                cmb_MIDI_InList.Items.Add(MidiIn.DeviceInfo(device).ProductName);
            }
            if (cmb_MIDI_InList.Items.Count > 0)
            {
                cmb_MIDI_InList.SelectedIndex = 0;
            }
        }
    }
}
