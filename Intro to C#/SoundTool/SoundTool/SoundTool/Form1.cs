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
using System.Windows.Forms;



namespace SoundTool
{
    public partial class Form1 : Form
    {

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
            FileDataStrings pathInfo;
            bool triggerMode;
            bool currentlyPlaying;
            bool keyDown;
            TextBox txt_name;
            Button btn_name;
            Label lbl_name;

            private IWavePlayer wavePlayer;
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

            public void toggleClicked ()
            {
                triggerMode = !triggerMode;
                updateToggleText();
            }
            public void fileDraggedin (string file)
            {
                pathInfo = new FileDataStrings(file);
                updateTextBox();
            }
            private IWavePlayer CreateWavePlayer()
            {
                return new WaveOut();
            }


            public void pressKey ()
            {
                keyDown = true;
                lbl_name.ForeColor = System.Drawing.Color.LimeGreen;
                if (triggerMode && pathInfo != null)
                {
                    if (currentlyPlaying) { stopPlayback(); }
                    startPlayback();
                }
                else if (!triggerMode && pathInfo != null)
                {
                    while (keyDown)
                    {
                        startPlayback();
                    }  
                }
            }

            public void releaseKey ()
            {
                keyDown = false;
                lbl_name.ForeColor = System.Drawing.Color.Black;
                if (triggerMode)
                {
                    currentlyPlaying = false;
                }
                else
                {
                    stopPlayback();
                    currentlyPlaying = false;
                }
            }

           

            void startPlayback()
            {
                wavePlayer = CreateWavePlayer();
                audioFileReader = new AudioFileReader(pathInfo.fullPath);
                //Add Volume Controls
                wavePlayer.Init(audioFileReader);
                wavePlayer.Play();
            }
            void stopPlayback()
            {
                wavePlayer.Stop();
            }
        };

        Dictionary<int, SamplerData> m_samples = new Dictionary<int, SamplerData>();
        



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
        private void lst_samplelist_DragEnter(object sender, DragEventArgs e)
        {
            string[] fileNames = (string[])e.Data.GetData(DataFormats.FileDrop, false);
            foreach (string file in fileNames)
            {
                lst_samplelist.Items.Add(file);
            }
            //e.Effect = DragDropEffects.All;
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            char key = Convert.ToChar(e.KeyCode);
            if (key > 96 && key < 106)
            {
                m_samples[key - 96].pressKey();
            }
        }

        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            char key = Convert.ToChar(e.KeyCode);
            if (key > 96 && key < 106)
            {
                m_samples[key - 96].releaseKey();
            }
        }



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
            string fileName = (string)e.Data.GetData(DataFormats.FileDrop, false);
            m_samples[id].fileDraggedin(fileName);
        }

        private void txt_samplefile_DragEnter(object sender, DragEventArgs e)
        {
            TextBox t = (TextBox)sender;
            string name = t.Name;
            int id = int.Parse(name.Substring(6, 1));
            string fileName = (string)e.Data.GetData(DataFormats.FileDrop, false);
            m_samples[id].fileDraggedin(fileName);
        }
    }
}
