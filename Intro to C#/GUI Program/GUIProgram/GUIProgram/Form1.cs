using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GUIProgram
{

    public partial class Form1 : Form
    {
        private int _score = 0;
        private string scoreText = "";

        public int score
        {
            get { return _score; }
            set
            {
                _score = value;
                scoreText = _score.ToString();
                OnScoreChanged();
            }
        }

     
        enum Type
        {
            Studio,
            AsylumFilm
        };

        Type m_guess;

      class Question
        {
            public Question(Type t, string s) { category = t; text = s; correct = false; }
            public Type category;
           public  string text;
            public bool correct;
        }
       const int NoQuestions = 10;

       Question[] quizList = new Question[NoQuestions]
        {
            new Question(Type.AsylumFilm, "Lava Sharks" ),
            new Question(Type.AsylumFilm, "Trolland" ),
            new Question(Type.Studio, "The Odd Gentlemen" ),
            new Question(Type.AsylumFilm, "I am Omega" ),
            new Question(Type.AsylumFilm, "Freakshow" ),
            new Question(Type.Studio, "Skygoblin" ),
            new Question(Type.AsylumFilm, "Bellyfruit" ),
            new Question(Type.Studio, "Stardock" ),
            new Question(Type.Studio, "Dr. Panda" ),
            new Question(Type.Studio, "Mojang" ),
        };

        private int currentQ_No = 0;
        Question Question_data;
        private string QuestionText = "";

        public int currentQuestion
        {
            get { return currentQ_No; }
            set
            {
                currentQ_No = value;
                Question_data = quizList[currentQ_No];
                QuestionText = Question_data.text;
                OnQuestionChanged();
            }
        }

        bool gameOver;
        public Form1()
            {
                InitializeComponent();
                startup();
            }
        void startup()
        {
            score = 0;
            //vartxt_scoreNumber.DataBindings.Add(new Binding("score", this, "scoreText"));
            currentQuestion = 0;
            gameOver = false;
            btn_Asylum.Text = "Movie by Low-budget Independant Film Studio, the Asylum";
            btn_indie.Text = "An indie Games Studio";
            foreach (Question quest in quizList)
            {
                //quest.correct = false;
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;
        private void btn_Asylum_Click(object sender, EventArgs e)
        {
            if (!gameOver)
            {
                m_guess = Type.AsylumFilm;
                CheckAnswer();
            }
            else
            {
                startup();
            }
        }

        private void btn_indie_Click(object sender, EventArgs e)
        {
            if (!gameOver)
            {
                m_guess = Type.Studio;
                CheckAnswer();
            }
            else
            {
                startup();
            }
            
        }

        private void CheckAnswer()
        {
            if (m_guess == Question_data.category)
            {
                score++;
                Question_data.correct = true;
            }
            if (currentQ_No < NoQuestions-1) { currentQuestion++; }
            else
            {
                btn_indie.Text = "Play Again?";
                btn_Asylum.Text = "Play Again?";
                QuestionText = "Game Over!";
                gameOver = true;
                answerList();
            }
        }

        private void OnScoreChanged()
        {
            vartxt_scoreNumber.Text = scoreText;
        }

        private void OnQuestionChanged()
        {
            vartxt_Question.Text = QuestionText;
        }

        private void answerList()
        {
            List<string> results = new List<string>();
            foreach (Question q in quizList)
            {
                if (q.correct == true)     { lst_gameSummary.ForeColor = System.Drawing.Color.ForestGreen; }
                if (q.correct == false)    { lst_gameSummary.ForeColor = System.Drawing.Color.OrangeRed; }
                Type group = q.category;
                group.ToString();
                results.Add(q.text + " - " + group); 
            }

            lst_gameSummary.DataSource = results;
        }

        private void lst_gameSummary_DrawItem(object sender, DrawItemEventArgs e)
        {
            e.DrawBackground();

            Brush myBrush = null;
            string value = ((ListBox)sender).Items[e.Index].ToString();

            foreach (Question q in quizList)
            {
                if(value.Contains(q.text))
                {
                    myBrush = (q.correct) ? Brushes.ForestGreen : Brushes.OrangeRed;
                    break;
                }
               
            }
            if(myBrush == null)
            {
                myBrush = Brushes.Gray;
            }

            e.Graphics.DrawString(value,
                  e.Font, myBrush, e.Bounds, StringFormat.GenericDefault);
            // If the ListBox has focus, draw a focus rectangle 
            // around the selected item.
            //
            e.DrawFocusRectangle();
        }
    }   
}
