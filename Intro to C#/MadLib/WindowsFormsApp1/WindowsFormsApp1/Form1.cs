using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        string[] nounList = new string[12]
            {
                "Anger", "Bulldozer", "Country", "Director", "Field",
                "House", "Mobile Phone", "Nerd", "Potato", "Skyscraper",
                "Teacher", "Zoologist"
            };

        string[] verbList = new string[12]
           {
                "Anger", "Bulldozer", "Country", "Director", "Field",
                "House", "Mobile Phone", "Nerd", "Potato", "Skyscraper",
                "Teacher", "Zoologist"
           };


        private void btn_randnoun_Click(object sender, EventArgs e)
        {

        }

        private void btn_randverb_Click(object sender, EventArgs e)
        {

        }

        private void btn_randadj_Click(object sender, EventArgs e)
        {
            
        }

        private void btn_submitNoun_Click(object sender, EventArgs e)
        {

        }
    }
}
