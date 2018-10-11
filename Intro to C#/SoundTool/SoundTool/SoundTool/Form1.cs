using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using NAudio.Wave;



namespace SoundTool
{
    public partial class Form1 : Form
    {
        public class FileInfo
        {
            public FileInfo(string FullPath)
            {

            }
           public string FullPath;
            public string shortPath;
        }
        public Form1()
        {
            InitializeComponent();
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

        public class keyPressSampler
        {
            private IWavePlayer wavePlayer;
            private AudioFileReader audioFileReader;
            public keyPressSampler(int i)
            {
                keyNo = i;
                inputcode = i + 96;
                data = null;
                playState = SampleMode.Trigger;
            }
            enum SampleMode
            {
                Trigger,
                Gate
            };
            int keyNo;
            SampleMode m_samplemode;
            FileInfo data;
            int inputcode;

            void TriggerGateManager ()
            {
                if (m_samplemode == SampleMode.Trigger)
                {

                }
                else if (m_samplemode == SampleMode.Gate)
                {

                }
            }

            void playsample()
            {
               
            }
            void startPlayback()
            {
                wavePlayer = CreateWavePlayer();
                audioFileReader = new AudioFileReader(data.FullPath);
                wavePlayer.Init(audioFileReader);
                wavePlayer.Play();
            }
            private IWavePlayer CreateWavePlayer()
            {
                return new WaveOut();
            }
        }
        
       
    }
}
