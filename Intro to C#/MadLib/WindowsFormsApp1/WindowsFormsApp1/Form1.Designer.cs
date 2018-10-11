namespace WindowsFormsApp1
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
            this.ttl_MadLib = new System.Windows.Forms.Label();
            this.ttl_noun = new System.Windows.Forms.Label();
            this.ttl_verbs = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.txt_noundesc = new System.Windows.Forms.Label();
            this.txt_verbdesc = new System.Windows.Forms.Label();
            this.txt_verb = new System.Windows.Forms.Label();
            this.btn_randnoun = new System.Windows.Forms.Button();
            this.btn_randverb = new System.Windows.Forms.Button();
            this.btn_randadj = new System.Windows.Forms.Button();
            this.inpt_noun = new System.Windows.Forms.TextBox();
            this.inpt_verb = new System.Windows.Forms.TextBox();
            this.inpt_adj = new System.Windows.Forms.TextBox();
            this.btn_submitNoun = new System.Windows.Forms.Button();
            this.btn_submitVerb = new System.Windows.Forms.Button();
            this.btn_submitAdj = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // ttl_MadLib
            // 
            this.ttl_MadLib.AutoSize = true;
            this.ttl_MadLib.Font = new System.Drawing.Font("Georgia", 60F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ttl_MadLib.ForeColor = System.Drawing.Color.DarkCyan;
            this.ttl_MadLib.Location = new System.Drawing.Point(147, 20);
            this.ttl_MadLib.Name = "ttl_MadLib";
            this.ttl_MadLib.Size = new System.Drawing.Size(474, 91);
            this.ttl_MadLib.TabIndex = 0;
            this.ttl_MadLib.Text = "MAD LIBS";
            // 
            // ttl_noun
            // 
            this.ttl_noun.AutoSize = true;
            this.ttl_noun.Font = new System.Drawing.Font("Georgia", 30F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ttl_noun.ForeColor = System.Drawing.Color.SkyBlue;
            this.ttl_noun.Location = new System.Drawing.Point(30, 147);
            this.ttl_noun.Name = "ttl_noun";
            this.ttl_noun.Size = new System.Drawing.Size(178, 46);
            this.ttl_noun.TabIndex = 0;
            this.ttl_noun.Text = "NOUNS";
            // 
            // ttl_verbs
            // 
            this.ttl_verbs.AutoSize = true;
            this.ttl_verbs.Font = new System.Drawing.Font("Georgia", 30F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))));
            this.ttl_verbs.ForeColor = System.Drawing.Color.SkyBlue;
            this.ttl_verbs.Location = new System.Drawing.Point(253, 147);
            this.ttl_verbs.Name = "ttl_verbs";
            this.ttl_verbs.Size = new System.Drawing.Size(167, 46);
            this.ttl_verbs.TabIndex = 0;
            this.ttl_verbs.Text = "VERBS";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Georgia", 30F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))));
            this.label2.ForeColor = System.Drawing.Color.SkyBlue;
            this.label2.Location = new System.Drawing.Point(475, 147);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(295, 46);
            this.label2.TabIndex = 0;
            this.label2.Text = "ADJECTIVES";
            // 
            // txt_noundesc
            // 
            this.txt_noundesc.AutoSize = true;
            this.txt_noundesc.Font = new System.Drawing.Font("Georgia", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txt_noundesc.Location = new System.Drawing.Point(35, 207);
            this.txt_noundesc.Name = "txt_noundesc";
            this.txt_noundesc.Size = new System.Drawing.Size(158, 90);
            this.txt_noundesc.TabIndex = 1;
            this.txt_noundesc.Text = "Nouns are words \r\nthat describe people, \r\nplaces or things.\r\n\r\nFor example:";
            this.txt_noundesc.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // txt_verbdesc
            // 
            this.txt_verbdesc.AutoSize = true;
            this.txt_verbdesc.Font = new System.Drawing.Font("Georgia", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txt_verbdesc.Location = new System.Drawing.Point(258, 207);
            this.txt_verbdesc.Name = "txt_verbdesc";
            this.txt_verbdesc.Size = new System.Drawing.Size(184, 90);
            this.txt_verbdesc.TabIndex = 1;
            this.txt_verbdesc.Text = "Verbs are \"action\" words\r\nPlease use the past form\r\nof verbs.\r\n\r\nFor example:";
            this.txt_verbdesc.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // txt_verb
            // 
            this.txt_verb.AutoSize = true;
            this.txt_verb.Font = new System.Drawing.Font("Georgia", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txt_verb.Location = new System.Drawing.Point(518, 207);
            this.txt_verb.Name = "txt_verb";
            this.txt_verb.Size = new System.Drawing.Size(192, 90);
            this.txt_verb.TabIndex = 1;
            this.txt_verb.Text = "Adjectives are words used\r\nto describe.\r\n\r\n\r\nFor example:";
            this.txt_verb.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // btn_randnoun
            // 
            this.btn_randnoun.BackColor = System.Drawing.Color.Turquoise;
            this.btn_randnoun.CausesValidation = false;
            this.btn_randnoun.Font = new System.Drawing.Font("Georgia", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_randnoun.Location = new System.Drawing.Point(64, 324);
            this.btn_randnoun.Name = "btn_randnoun";
            this.btn_randnoun.Size = new System.Drawing.Size(112, 45);
            this.btn_randnoun.TabIndex = 2;
            this.btn_randnoun.Text = "button1";
            this.btn_randnoun.UseVisualStyleBackColor = false;
            this.btn_randnoun.Click += new System.EventHandler(this.btn_randnoun_Click);
            // 
            // btn_randverb
            // 
            this.btn_randverb.BackColor = System.Drawing.Color.Turquoise;
            this.btn_randverb.CausesValidation = false;
            this.btn_randverb.Font = new System.Drawing.Font("Georgia", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_randverb.Location = new System.Drawing.Point(295, 324);
            this.btn_randverb.Name = "btn_randverb";
            this.btn_randverb.Size = new System.Drawing.Size(112, 45);
            this.btn_randverb.TabIndex = 2;
            this.btn_randverb.Text = "button1";
            this.btn_randverb.UseVisualStyleBackColor = false;
            this.btn_randverb.Click += new System.EventHandler(this.btn_randverb_Click);
            // 
            // btn_randadj
            // 
            this.btn_randadj.BackColor = System.Drawing.Color.Turquoise;
            this.btn_randadj.CausesValidation = false;
            this.btn_randadj.Font = new System.Drawing.Font("Georgia", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_randadj.Location = new System.Drawing.Point(553, 324);
            this.btn_randadj.Name = "btn_randadj";
            this.btn_randadj.Size = new System.Drawing.Size(112, 45);
            this.btn_randadj.TabIndex = 2;
            this.btn_randadj.Text = "button1";
            this.btn_randadj.UseVisualStyleBackColor = false;
            this.btn_randadj.Click += new System.EventHandler(this.btn_randadj_Click);
            // 
            // inpt_noun
            // 
            this.inpt_noun.Location = new System.Drawing.Point(50, 375);
            this.inpt_noun.Name = "inpt_noun";
            this.inpt_noun.Size = new System.Drawing.Size(143, 20);
            this.inpt_noun.TabIndex = 3;
            // 
            // inpt_verb
            // 
            this.inpt_verb.Location = new System.Drawing.Point(277, 375);
            this.inpt_verb.Name = "inpt_verb";
            this.inpt_verb.Size = new System.Drawing.Size(143, 20);
            this.inpt_verb.TabIndex = 3;
            // 
            // inpt_adj
            // 
            this.inpt_adj.Location = new System.Drawing.Point(538, 375);
            this.inpt_adj.Name = "inpt_adj";
            this.inpt_adj.Size = new System.Drawing.Size(143, 20);
            this.inpt_adj.TabIndex = 3;
            // 
            // btn_submitNoun
            // 
            this.btn_submitNoun.BackColor = System.Drawing.Color.DeepSkyBlue;
            this.btn_submitNoun.CausesValidation = false;
            this.btn_submitNoun.Font = new System.Drawing.Font("Georgia", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_submitNoun.Location = new System.Drawing.Point(81, 401);
            this.btn_submitNoun.Name = "btn_submitNoun";
            this.btn_submitNoun.Size = new System.Drawing.Size(82, 25);
            this.btn_submitNoun.TabIndex = 2;
            this.btn_submitNoun.Text = "SUBMIT";
            this.btn_submitNoun.UseVisualStyleBackColor = false;
            // 
            // btn_submitVerb
            // 
            this.btn_submitVerb.BackColor = System.Drawing.Color.DeepSkyBlue;
            this.btn_submitVerb.CausesValidation = false;
            this.btn_submitVerb.Font = new System.Drawing.Font("Georgia", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_submitVerb.Location = new System.Drawing.Point(309, 401);
            this.btn_submitVerb.Name = "btn_submitVerb";
            this.btn_submitVerb.Size = new System.Drawing.Size(82, 25);
            this.btn_submitVerb.TabIndex = 2;
            this.btn_submitVerb.Text = "SUBMIT";
            this.btn_submitVerb.UseVisualStyleBackColor = false;
            // 
            // btn_submitAdj
            // 
            this.btn_submitAdj.BackColor = System.Drawing.Color.DeepSkyBlue;
            this.btn_submitAdj.CausesValidation = false;
            this.btn_submitAdj.Font = new System.Drawing.Font("Georgia", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_submitAdj.Location = new System.Drawing.Point(569, 401);
            this.btn_submitAdj.Name = "btn_submitAdj";
            this.btn_submitAdj.Size = new System.Drawing.Size(82, 25);
            this.btn_submitAdj.TabIndex = 2;
            this.btn_submitAdj.Text = "SUBMIT";
            this.btn_submitAdj.UseVisualStyleBackColor = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.LightCyan;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.inpt_adj);
            this.Controls.Add(this.inpt_verb);
            this.Controls.Add(this.inpt_noun);
            this.Controls.Add(this.btn_randadj);
            this.Controls.Add(this.btn_randverb);
            this.Controls.Add(this.btn_submitAdj);
            this.Controls.Add(this.btn_submitVerb);
            this.Controls.Add(this.btn_submitNoun);
            this.Controls.Add(this.btn_randnoun);
            this.Controls.Add(this.txt_verb);
            this.Controls.Add(this.txt_verbdesc);
            this.Controls.Add(this.txt_noundesc);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.ttl_verbs);
            this.Controls.Add(this.ttl_noun);
            this.Controls.Add(this.ttl_MadLib);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label ttl_MadLib;
        private System.Windows.Forms.Label ttl_noun;
        private System.Windows.Forms.Label ttl_verbs;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label txt_noundesc;
        private System.Windows.Forms.Label txt_verbdesc;
        private System.Windows.Forms.Label txt_verb;
        private System.Windows.Forms.Button btn_randnoun;
        private System.Windows.Forms.Button btn_randverb;
        private System.Windows.Forms.Button btn_randadj;
        private System.Windows.Forms.TextBox inpt_noun;
        private System.Windows.Forms.TextBox inpt_verb;
        private System.Windows.Forms.TextBox inpt_adj;
        private System.Windows.Forms.Button btn_submitNoun;
        private System.Windows.Forms.Button btn_submitVerb;
        private System.Windows.Forms.Button btn_submitAdj;
    }
}

