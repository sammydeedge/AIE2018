namespace GUIProgram
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.btn_indie = new System.Windows.Forms.Button();
            this.btn_Asylum = new System.Windows.Forms.Button();
            this.vartxt_scoreNumber = new System.Windows.Forms.Label();
            this.txt_Title = new System.Windows.Forms.Label();
            this.txt_scoreTitle = new System.Windows.Forms.Label();
            this.vartxt_Question = new System.Windows.Forms.Label();
            this.lst_gameSummary = new System.Windows.Forms.ListBox();
            this.form1BindingSource = new System.Windows.Forms.BindingSource(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.form1BindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // btn_indie
            // 
            this.btn_indie.BackColor = System.Drawing.Color.Orange;
            this.btn_indie.Font = new System.Drawing.Font("Comic Sans MS", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_indie.Location = new System.Drawing.Point(106, 254);
            this.btn_indie.Name = "btn_indie";
            this.btn_indie.Size = new System.Drawing.Size(198, 82);
            this.btn_indie.TabIndex = 1;
            this.btn_indie.Text = "Indie Game Studio";
            this.btn_indie.UseVisualStyleBackColor = false;
            this.btn_indie.Click += new System.EventHandler(this.btn_indie_Click);
            // 
            // btn_Asylum
            // 
            this.btn_Asylum.BackColor = System.Drawing.Color.YellowGreen;
            this.btn_Asylum.Font = new System.Drawing.Font("Comic Sans MS", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_Asylum.Location = new System.Drawing.Point(517, 254);
            this.btn_Asylum.Name = "btn_Asylum";
            this.btn_Asylum.Size = new System.Drawing.Size(221, 95);
            this.btn_Asylum.TabIndex = 2;
            this.btn_Asylum.Text = "Movie by Low-budget independant studio, The Asylum";
            this.btn_Asylum.UseVisualStyleBackColor = false;
            this.btn_Asylum.Click += new System.EventHandler(this.btn_Asylum_Click);
            // 
            // vartxt_scoreNumber
            // 
            this.vartxt_scoreNumber.AutoSize = true;
            this.vartxt_scoreNumber.Font = new System.Drawing.Font("Lucida Console", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.vartxt_scoreNumber.Location = new System.Drawing.Point(373, 397);
            this.vartxt_scoreNumber.Name = "vartxt_scoreNumber";
            this.vartxt_scoreNumber.Size = new System.Drawing.Size(81, 19);
            this.vartxt_scoreNumber.TabIndex = 4;
            this.vartxt_scoreNumber.Text = "label1";
            // 
            // txt_Title
            // 
            this.txt_Title.AutoSize = true;
            this.txt_Title.Font = new System.Drawing.Font("Century Gothic", 50.25F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txt_Title.ForeColor = System.Drawing.Color.Red;
            this.txt_Title.Location = new System.Drawing.Point(199, 9);
            this.txt_Title.Name = "txt_Title";
            this.txt_Title.Size = new System.Drawing.Size(394, 82);
            this.txt_Title.TabIndex = 5;
            this.txt_Title.Text = "DIS OR DAT";
            // 
            // txt_scoreTitle
            // 
            this.txt_scoreTitle.AutoSize = true;
            this.txt_scoreTitle.Font = new System.Drawing.Font("Century Gothic", 21.75F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txt_scoreTitle.ForeColor = System.Drawing.Color.Tomato;
            this.txt_scoreTitle.Location = new System.Drawing.Point(358, 344);
            this.txt_scoreTitle.Name = "txt_scoreTitle";
            this.txt_scoreTitle.Size = new System.Drawing.Size(109, 36);
            this.txt_scoreTitle.TabIndex = 6;
            this.txt_scoreTitle.Text = "SCORE";
            // 
            // vartxt_Question
            // 
            this.vartxt_Question.AutoSize = true;
            this.vartxt_Question.BackColor = System.Drawing.Color.Gold;
            this.vartxt_Question.Font = new System.Drawing.Font("Lucida Console", 14.25F, System.Drawing.FontStyle.Bold);
            this.vartxt_Question.Location = new System.Drawing.Point(360, 156);
            this.vartxt_Question.Name = "vartxt_Question";
            this.vartxt_Question.Size = new System.Drawing.Size(81, 19);
            this.vartxt_Question.TabIndex = 7;
            this.vartxt_Question.Text = "label1";
            this.vartxt_Question.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lst_gameSummary
            // 
            this.lst_gameSummary.DrawMode = System.Windows.Forms.DrawMode.OwnerDrawFixed;
            this.lst_gameSummary.Font = new System.Drawing.Font("Lucida Console", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lst_gameSummary.ForeColor = System.Drawing.Color.OrangeRed;
            this.lst_gameSummary.FormattingEnabled = true;
            this.lst_gameSummary.ItemHeight = 16;
            this.lst_gameSummary.Location = new System.Drawing.Point(12, 25);
            this.lst_gameSummary.Name = "lst_gameSummary";
            this.lst_gameSummary.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.lst_gameSummary.Size = new System.Drawing.Size(187, 164);
            this.lst_gameSummary.TabIndex = 8;
            this.lst_gameSummary.DrawItem += new System.Windows.Forms.DrawItemEventHandler(this.lst_gameSummary_DrawItem);
            // 
            // form1BindingSource
            // 
            this.form1BindingSource.DataSource = typeof(GUIProgram.Form1);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.lst_gameSummary);
            this.Controls.Add(this.vartxt_Question);
            this.Controls.Add(this.txt_scoreTitle);
            this.Controls.Add(this.txt_Title);
            this.Controls.Add(this.vartxt_scoreNumber);
            this.Controls.Add(this.btn_Asylum);
            this.Controls.Add(this.btn_indie);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.form1BindingSource)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Button btn_indie;
        private System.Windows.Forms.Button btn_Asylum;
        private System.Windows.Forms.Label vartxt_scoreNumber;
        private System.Windows.Forms.Label txt_Title;
        private System.Windows.Forms.Label txt_scoreTitle;
        private System.Windows.Forms.Label vartxt_Question;
        private System.Windows.Forms.ListBox lst_gameSummary;
        private System.Windows.Forms.BindingSource form1BindingSource;
    }
}

