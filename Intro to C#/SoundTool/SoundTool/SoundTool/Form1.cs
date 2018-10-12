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



namespace SoundTool
{
    public partial class Form1 : Form
    {

        public class FileDataStrings
        {
            public FileDataStrings(string path) { fullPath = path; displayName = Path.GetFileName(path); }
            string fullPath;
            string displayName;
        }

        public struct SamplerData
        {
            public SamplerData(int Num, TextBox txt, Button btn)
            {
                KP_val = Num;
                pathInfo = null;
                keyCode = (char)(Num + 96);
                triggerMode = true;
                txt_name = txt;
                btn_name = btn;
            }
            int KP_val;
            FileDataStrings pathInfo;
            char keyCode;
            bool triggerMode;
            TextBox txt_name;
            Button btn_name;
        };

        public struct Lookup_SamplerData
        {
            public Lookup_SamplerData(int i, TextBox txt, Button btn) { KP_Key = i; KP_linkedData = new SamplerData(1, txt, btn); }
            int KP_Key;
            SamplerData KP_linkedData;
        }


        Lookup_SamplerData[] m_dictionary;

        public Form1()
        {
            InitializeComponent();

            m_dictionary = new Lookup_SamplerData[9]
            {
              new Lookup_SamplerData(1, txt_KP1file, btn_KP1Toggle),
              new Lookup_SamplerData(2, txt_KP2file, btn_KP2Toggle),
              new Lookup_SamplerData(3, txt_KP3file, btn_KP3Toggle),
              new Lookup_SamplerData(4, txt_KP4file, btn_KP4Toggle),
              new Lookup_SamplerData(5, txt_KP5file, btn_KP5Toggle),
              new Lookup_SamplerData(6, txt_KP6file, btn_KP6Toggle),
              new Lookup_SamplerData(7, txt_KP7file, btn_KP7Toggle),
              new Lookup_SamplerData(8, txt_KP8file, btn_KP8Toggle),
              new Lookup_SamplerData(9, txt_KP9file, btn_KP9Toggle),
            };
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
            e.Effect = DragDropEffects.All;
        }
        private void lst_samplelist_DragDrop(object sender, DragEventArgs e)
        {
            string[] fileNames = (string[])e.Data.GetData(DataFormats.FileDrop, false);
            foreach (string file in fileNames)
            {
                lst_samplelist.Items.Add(file);
            }
        }



        public class keyPressSampler
        {
            private IWavePlayer wavePlayer;
            private AudioFileReader audioFileReader;
            
            void playsample()
            {
               
            }
            void startPlayback()
            {
                wavePlayer = CreateWavePlayer();
                //audioFileReader = new AudioFileReader(data.FullPath);
                wavePlayer.Init(audioFileReader);
                wavePlayer.Play();
            }
            private IWavePlayer CreateWavePlayer()
            {
                return new WaveOut();
            }
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            char key = Convert.ToChar(e.KeyCode);
            if (key > 96 && key < 106)
            {
                foreach (Lookup_SamplerData entry in m_dictionary )
                {
                    if (entry.KP_linkedData.keyCode) //Get function?
                        //run application (may require referencing the class object in the dictionary?
                }
            }
        }
    }
}
