namespace SoundTool
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
            this.lst_samplelist = new System.Windows.Forms.ListBox();
            this.btn_addsamples = new System.Windows.Forms.Button();
            this.lbl_KP7 = new System.Windows.Forms.Label();
            this.lbl_KP8 = new System.Windows.Forms.Label();
            this.lbl_KP9 = new System.Windows.Forms.Label();
            this.lbl_KP4 = new System.Windows.Forms.Label();
            this.lbl_KP5 = new System.Windows.Forms.Label();
            this.lbl_KP6 = new System.Windows.Forms.Label();
            this.lbl_KP1 = new System.Windows.Forms.Label();
            this.lbl_KP2 = new System.Windows.Forms.Label();
            this.lbl_KP3 = new System.Windows.Forms.Label();
            this.txt_KP7file = new System.Windows.Forms.TextBox();
            this.txt_KP8file = new System.Windows.Forms.TextBox();
            this.txt_KP9file = new System.Windows.Forms.TextBox();
            this.txt_KP4file = new System.Windows.Forms.TextBox();
            this.txt_KP5file = new System.Windows.Forms.TextBox();
            this.txt_KP6file = new System.Windows.Forms.TextBox();
            this.txt_KP1file = new System.Windows.Forms.TextBox();
            this.txt_KP2file = new System.Windows.Forms.TextBox();
            this.txt_KP3file = new System.Windows.Forms.TextBox();
            this.btn_KP7Toggle = new System.Windows.Forms.Button();
            this.btn_KP8Toggle = new System.Windows.Forms.Button();
            this.btn_KP9Toggle = new System.Windows.Forms.Button();
            this.btn_KP4Toggle = new System.Windows.Forms.Button();
            this.btn_KP5Toggle = new System.Windows.Forms.Button();
            this.btn_KP6Toggle = new System.Windows.Forms.Button();
            this.btn_KP1Toggle = new System.Windows.Forms.Button();
            this.btn_KP2Toggle = new System.Windows.Forms.Button();
            this.btn_KP3Toggle = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.waveViewer = new NAudio.Gui.WaveViewer();
            this.waveViewer1 = new NAudio.Gui.WaveViewer();
            this.label1 = new System.Windows.Forms.Label();
            this.panel2 = new System.Windows.Forms.Panel();
            this.btn_RECSTOP = new System.Windows.Forms.Button();
            this.cmb_InputsList = new System.Windows.Forms.ComboBox();
            this.lbl_REC_Audio = new System.Windows.Forms.Label();
            this.panel3 = new System.Windows.Forms.Panel();
            this.btn_MIDI_PLAY = new System.Windows.Forms.Button();
            this.btn_MIDI_RECSTOP = new System.Windows.Forms.Button();
            this.cmb_MIDI_FileList = new System.Windows.Forms.ComboBox();
            this.lbl_MIDI = new System.Windows.Forms.Label();
            this.cmb_MIDI_InList = new System.Windows.Forms.ComboBox();
            this.panel1.SuspendLayout();
            this.panel2.SuspendLayout();
            this.panel3.SuspendLayout();
            this.SuspendLayout();
            // 
            // lst_samplelist
            // 
            this.lst_samplelist.AllowDrop = true;
            this.lst_samplelist.FormattingEnabled = true;
            this.lst_samplelist.Location = new System.Drawing.Point(27, 66);
            this.lst_samplelist.Name = "lst_samplelist";
            this.lst_samplelist.Size = new System.Drawing.Size(118, 342);
            this.lst_samplelist.TabIndex = 1;
            this.lst_samplelist.DragEnter += new System.Windows.Forms.DragEventHandler(this.lst_samplelist_DragEnter);
            this.lst_samplelist.MouseDown += new System.Windows.Forms.MouseEventHandler(this.lst_samplelist_MouseDown);
            // 
            // btn_addsamples
            // 
            this.btn_addsamples.Location = new System.Drawing.Point(27, 29);
            this.btn_addsamples.Name = "btn_addsamples";
            this.btn_addsamples.Size = new System.Drawing.Size(118, 23);
            this.btn_addsamples.TabIndex = 2;
            this.btn_addsamples.Text = "Add Samples";
            this.btn_addsamples.UseVisualStyleBackColor = true;
            this.btn_addsamples.Click += new System.EventHandler(this.btn_addsamples_Click);
            // 
            // lbl_KP7
            // 
            this.lbl_KP7.AutoSize = true;
            this.lbl_KP7.Font = new System.Drawing.Font("Century Gothic", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_KP7.Location = new System.Drawing.Point(236, 114);
            this.lbl_KP7.Name = "lbl_KP7";
            this.lbl_KP7.Size = new System.Drawing.Size(25, 28);
            this.lbl_KP7.TabIndex = 3;
            this.lbl_KP7.Text = "7";
            // 
            // lbl_KP8
            // 
            this.lbl_KP8.AutoSize = true;
            this.lbl_KP8.Font = new System.Drawing.Font("Century Gothic", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_KP8.Location = new System.Drawing.Point(384, 114);
            this.lbl_KP8.Name = "lbl_KP8";
            this.lbl_KP8.Size = new System.Drawing.Size(25, 28);
            this.lbl_KP8.TabIndex = 3;
            this.lbl_KP8.Text = "8";
            // 
            // lbl_KP9
            // 
            this.lbl_KP9.AutoSize = true;
            this.lbl_KP9.Font = new System.Drawing.Font("Century Gothic", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_KP9.Location = new System.Drawing.Point(543, 114);
            this.lbl_KP9.Name = "lbl_KP9";
            this.lbl_KP9.Size = new System.Drawing.Size(25, 28);
            this.lbl_KP9.TabIndex = 3;
            this.lbl_KP9.Text = "9";
            // 
            // lbl_KP4
            // 
            this.lbl_KP4.AutoSize = true;
            this.lbl_KP4.Font = new System.Drawing.Font("Century Gothic", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_KP4.Location = new System.Drawing.Point(236, 232);
            this.lbl_KP4.Name = "lbl_KP4";
            this.lbl_KP4.Size = new System.Drawing.Size(25, 28);
            this.lbl_KP4.TabIndex = 3;
            this.lbl_KP4.Text = "4";
            // 
            // lbl_KP5
            // 
            this.lbl_KP5.AutoSize = true;
            this.lbl_KP5.Font = new System.Drawing.Font("Century Gothic", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_KP5.Location = new System.Drawing.Point(384, 232);
            this.lbl_KP5.Name = "lbl_KP5";
            this.lbl_KP5.Size = new System.Drawing.Size(25, 28);
            this.lbl_KP5.TabIndex = 3;
            this.lbl_KP5.Text = "5";
            // 
            // lbl_KP6
            // 
            this.lbl_KP6.AutoSize = true;
            this.lbl_KP6.Font = new System.Drawing.Font("Century Gothic", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_KP6.Location = new System.Drawing.Point(543, 232);
            this.lbl_KP6.Name = "lbl_KP6";
            this.lbl_KP6.Size = new System.Drawing.Size(25, 28);
            this.lbl_KP6.TabIndex = 3;
            this.lbl_KP6.Text = "6";
            // 
            // lbl_KP1
            // 
            this.lbl_KP1.AutoSize = true;
            this.lbl_KP1.Font = new System.Drawing.Font("Century Gothic", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_KP1.Location = new System.Drawing.Point(236, 342);
            this.lbl_KP1.Name = "lbl_KP1";
            this.lbl_KP1.Size = new System.Drawing.Size(25, 28);
            this.lbl_KP1.TabIndex = 3;
            this.lbl_KP1.Text = "1";
            // 
            // lbl_KP2
            // 
            this.lbl_KP2.AutoSize = true;
            this.lbl_KP2.Font = new System.Drawing.Font("Century Gothic", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_KP2.Location = new System.Drawing.Point(384, 342);
            this.lbl_KP2.Name = "lbl_KP2";
            this.lbl_KP2.Size = new System.Drawing.Size(25, 28);
            this.lbl_KP2.TabIndex = 3;
            this.lbl_KP2.Text = "2";
            // 
            // lbl_KP3
            // 
            this.lbl_KP3.AutoSize = true;
            this.lbl_KP3.Font = new System.Drawing.Font("Century Gothic", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_KP3.Location = new System.Drawing.Point(543, 342);
            this.lbl_KP3.Name = "lbl_KP3";
            this.lbl_KP3.Size = new System.Drawing.Size(25, 28);
            this.lbl_KP3.TabIndex = 3;
            this.lbl_KP3.Text = "3";
            // 
            // txt_KP7file
            // 
            this.txt_KP7file.AllowDrop = true;
            this.txt_KP7file.ForeColor = System.Drawing.Color.Black;
            this.txt_KP7file.Location = new System.Drawing.Point(197, 145);
            this.txt_KP7file.Name = "txt_KP7file";
            this.txt_KP7file.Size = new System.Drawing.Size(100, 20);
            this.txt_KP7file.TabIndex = 4;
            this.txt_KP7file.DragDrop += new System.Windows.Forms.DragEventHandler(this.txt_samplefile_DragDrop);
            this.txt_KP7file.DragEnter += new System.Windows.Forms.DragEventHandler(this.txt_samplefile_DragEnter);
            // 
            // txt_KP8file
            // 
            this.txt_KP8file.AllowDrop = true;
            this.txt_KP8file.Location = new System.Drawing.Point(345, 145);
            this.txt_KP8file.Name = "txt_KP8file";
            this.txt_KP8file.Size = new System.Drawing.Size(100, 20);
            this.txt_KP8file.TabIndex = 4;
            this.txt_KP8file.DragDrop += new System.Windows.Forms.DragEventHandler(this.txt_samplefile_DragDrop);
            this.txt_KP8file.DragEnter += new System.Windows.Forms.DragEventHandler(this.txt_samplefile_DragEnter);
            // 
            // txt_KP9file
            // 
            this.txt_KP9file.AllowDrop = true;
            this.txt_KP9file.Location = new System.Drawing.Point(505, 145);
            this.txt_KP9file.Name = "txt_KP9file";
            this.txt_KP9file.Size = new System.Drawing.Size(100, 20);
            this.txt_KP9file.TabIndex = 4;
            this.txt_KP9file.DragDrop += new System.Windows.Forms.DragEventHandler(this.txt_samplefile_DragDrop);
            this.txt_KP9file.DragEnter += new System.Windows.Forms.DragEventHandler(this.txt_samplefile_DragEnter);
            // 
            // txt_KP4file
            // 
            this.txt_KP4file.AllowDrop = true;
            this.txt_KP4file.Location = new System.Drawing.Point(197, 263);
            this.txt_KP4file.Name = "txt_KP4file";
            this.txt_KP4file.Size = new System.Drawing.Size(100, 20);
            this.txt_KP4file.TabIndex = 4;
            this.txt_KP4file.DragDrop += new System.Windows.Forms.DragEventHandler(this.txt_samplefile_DragDrop);
            this.txt_KP4file.DragEnter += new System.Windows.Forms.DragEventHandler(this.txt_samplefile_DragEnter);
            // 
            // txt_KP5file
            // 
            this.txt_KP5file.AllowDrop = true;
            this.txt_KP5file.Location = new System.Drawing.Point(345, 263);
            this.txt_KP5file.Name = "txt_KP5file";
            this.txt_KP5file.Size = new System.Drawing.Size(100, 20);
            this.txt_KP5file.TabIndex = 4;
            this.txt_KP5file.DragDrop += new System.Windows.Forms.DragEventHandler(this.txt_samplefile_DragDrop);
            this.txt_KP5file.DragEnter += new System.Windows.Forms.DragEventHandler(this.txt_samplefile_DragEnter);
            // 
            // txt_KP6file
            // 
            this.txt_KP6file.AllowDrop = true;
            this.txt_KP6file.Location = new System.Drawing.Point(505, 263);
            this.txt_KP6file.Name = "txt_KP6file";
            this.txt_KP6file.Size = new System.Drawing.Size(100, 20);
            this.txt_KP6file.TabIndex = 4;
            this.txt_KP6file.DragDrop += new System.Windows.Forms.DragEventHandler(this.txt_samplefile_DragDrop);
            this.txt_KP6file.DragEnter += new System.Windows.Forms.DragEventHandler(this.txt_samplefile_DragEnter);
            // 
            // txt_KP1file
            // 
            this.txt_KP1file.AllowDrop = true;
            this.txt_KP1file.Location = new System.Drawing.Point(197, 373);
            this.txt_KP1file.Name = "txt_KP1file";
            this.txt_KP1file.Size = new System.Drawing.Size(100, 20);
            this.txt_KP1file.TabIndex = 4;
            this.txt_KP1file.DragDrop += new System.Windows.Forms.DragEventHandler(this.txt_samplefile_DragDrop);
            this.txt_KP1file.DragEnter += new System.Windows.Forms.DragEventHandler(this.txt_samplefile_DragEnter);
            // 
            // txt_KP2file
            // 
            this.txt_KP2file.AllowDrop = true;
            this.txt_KP2file.Location = new System.Drawing.Point(345, 373);
            this.txt_KP2file.Name = "txt_KP2file";
            this.txt_KP2file.Size = new System.Drawing.Size(100, 20);
            this.txt_KP2file.TabIndex = 4;
            this.txt_KP2file.DragDrop += new System.Windows.Forms.DragEventHandler(this.txt_samplefile_DragDrop);
            this.txt_KP2file.DragEnter += new System.Windows.Forms.DragEventHandler(this.txt_samplefile_DragEnter);
            // 
            // txt_KP3file
            // 
            this.txt_KP3file.AllowDrop = true;
            this.txt_KP3file.Location = new System.Drawing.Point(505, 373);
            this.txt_KP3file.Name = "txt_KP3file";
            this.txt_KP3file.Size = new System.Drawing.Size(100, 20);
            this.txt_KP3file.TabIndex = 4;
            this.txt_KP3file.DragDrop += new System.Windows.Forms.DragEventHandler(this.txt_samplefile_DragDrop);
            this.txt_KP3file.DragEnter += new System.Windows.Forms.DragEventHandler(this.txt_samplefile_DragEnter);
            // 
            // btn_KP7Toggle
            // 
            this.btn_KP7Toggle.Location = new System.Drawing.Point(212, 171);
            this.btn_KP7Toggle.Name = "btn_KP7Toggle";
            this.btn_KP7Toggle.Size = new System.Drawing.Size(75, 23);
            this.btn_KP7Toggle.TabIndex = 5;
            this.btn_KP7Toggle.Text = "7 Toggle";
            this.btn_KP7Toggle.UseVisualStyleBackColor = true;
            this.btn_KP7Toggle.Click += new System.EventHandler(this.btn_Toggle_Click);
            // 
            // btn_KP8Toggle
            // 
            this.btn_KP8Toggle.Location = new System.Drawing.Point(358, 171);
            this.btn_KP8Toggle.Name = "btn_KP8Toggle";
            this.btn_KP8Toggle.Size = new System.Drawing.Size(75, 23);
            this.btn_KP8Toggle.TabIndex = 5;
            this.btn_KP8Toggle.Text = "8 Toggle";
            this.btn_KP8Toggle.UseVisualStyleBackColor = true;
            this.btn_KP8Toggle.Click += new System.EventHandler(this.btn_Toggle_Click);
            // 
            // btn_KP9Toggle
            // 
            this.btn_KP9Toggle.Location = new System.Drawing.Point(514, 171);
            this.btn_KP9Toggle.Name = "btn_KP9Toggle";
            this.btn_KP9Toggle.Size = new System.Drawing.Size(75, 23);
            this.btn_KP9Toggle.TabIndex = 5;
            this.btn_KP9Toggle.Text = "9 Toggle";
            this.btn_KP9Toggle.UseVisualStyleBackColor = true;
            this.btn_KP9Toggle.Click += new System.EventHandler(this.btn_Toggle_Click);
            // 
            // btn_KP4Toggle
            // 
            this.btn_KP4Toggle.Location = new System.Drawing.Point(212, 289);
            this.btn_KP4Toggle.Name = "btn_KP4Toggle";
            this.btn_KP4Toggle.Size = new System.Drawing.Size(75, 23);
            this.btn_KP4Toggle.TabIndex = 5;
            this.btn_KP4Toggle.Text = "4 Toggle";
            this.btn_KP4Toggle.UseVisualStyleBackColor = true;
            this.btn_KP4Toggle.Click += new System.EventHandler(this.btn_Toggle_Click);
            // 
            // btn_KP5Toggle
            // 
            this.btn_KP5Toggle.Location = new System.Drawing.Point(358, 289);
            this.btn_KP5Toggle.Name = "btn_KP5Toggle";
            this.btn_KP5Toggle.Size = new System.Drawing.Size(75, 23);
            this.btn_KP5Toggle.TabIndex = 5;
            this.btn_KP5Toggle.Text = "5 Toggle";
            this.btn_KP5Toggle.UseVisualStyleBackColor = true;
            this.btn_KP5Toggle.Click += new System.EventHandler(this.btn_Toggle_Click);
            // 
            // btn_KP6Toggle
            // 
            this.btn_KP6Toggle.Location = new System.Drawing.Point(514, 289);
            this.btn_KP6Toggle.Name = "btn_KP6Toggle";
            this.btn_KP6Toggle.Size = new System.Drawing.Size(75, 23);
            this.btn_KP6Toggle.TabIndex = 5;
            this.btn_KP6Toggle.Text = "6 Toggle";
            this.btn_KP6Toggle.UseVisualStyleBackColor = true;
            this.btn_KP6Toggle.Click += new System.EventHandler(this.btn_Toggle_Click);
            // 
            // btn_KP1Toggle
            // 
            this.btn_KP1Toggle.Location = new System.Drawing.Point(212, 398);
            this.btn_KP1Toggle.Name = "btn_KP1Toggle";
            this.btn_KP1Toggle.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.btn_KP1Toggle.Size = new System.Drawing.Size(75, 23);
            this.btn_KP1Toggle.TabIndex = 5;
            this.btn_KP1Toggle.Text = "1 Toggle";
            this.btn_KP1Toggle.UseVisualStyleBackColor = true;
            this.btn_KP1Toggle.Click += new System.EventHandler(this.btn_Toggle_Click);
            // 
            // btn_KP2Toggle
            // 
            this.btn_KP2Toggle.Location = new System.Drawing.Point(358, 398);
            this.btn_KP2Toggle.Name = "btn_KP2Toggle";
            this.btn_KP2Toggle.Size = new System.Drawing.Size(75, 23);
            this.btn_KP2Toggle.TabIndex = 5;
            this.btn_KP2Toggle.Text = "2 Toggle";
            this.btn_KP2Toggle.UseVisualStyleBackColor = true;
            this.btn_KP2Toggle.Click += new System.EventHandler(this.btn_Toggle_Click);
            // 
            // btn_KP3Toggle
            // 
            this.btn_KP3Toggle.Location = new System.Drawing.Point(514, 398);
            this.btn_KP3Toggle.Name = "btn_KP3Toggle";
            this.btn_KP3Toggle.Size = new System.Drawing.Size(75, 23);
            this.btn_KP3Toggle.TabIndex = 5;
            this.btn_KP3Toggle.Text = "3 Toggle";
            this.btn_KP3Toggle.UseVisualStyleBackColor = true;
            this.btn_KP3Toggle.Click += new System.EventHandler(this.btn_Toggle_Click);
            // 
            // panel1
            // 
            this.panel1.AllowDrop = true;
            this.panel1.BackColor = System.Drawing.Color.Bisque;
            this.panel1.Controls.Add(this.waveViewer);
            this.panel1.Controls.Add(this.waveViewer1);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Location = new System.Drawing.Point(185, 13);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(590, 98);
            this.panel1.TabIndex = 7;
            this.panel1.DragDrop += new System.Windows.Forms.DragEventHandler(this.waveViewer_DragDrop);
            this.panel1.DragEnter += new System.Windows.Forms.DragEventHandler(this.waveViewer_DragDrop);
            // 
            // waveViewer
            // 
            this.waveViewer.Dock = System.Windows.Forms.DockStyle.Fill;
            this.waveViewer.Location = new System.Drawing.Point(0, 0);
            this.waveViewer.Name = "waveViewer";
            this.waveViewer.SamplesPerPixel = 128;
            this.waveViewer.Size = new System.Drawing.Size(590, 75);
            this.waveViewer.StartPosition = ((long)(0));
            this.waveViewer.TabIndex = 3;
            this.waveViewer.WaveStream = null;
            this.waveViewer.DragDrop += new System.Windows.Forms.DragEventHandler(this.waveViewer_DragDrop);
            this.waveViewer.DragEnter += new System.Windows.Forms.DragEventHandler(this.waveViewer_DragDrop);
            // 
            // waveViewer1
            // 
            this.waveViewer1.Location = new System.Drawing.Point(392, 48);
            this.waveViewer1.Name = "waveViewer1";
            this.waveViewer1.SamplesPerPixel = 128;
            this.waveViewer1.Size = new System.Drawing.Size(150, 150);
            this.waveViewer1.StartPosition = ((long)(0));
            this.waveViewer1.TabIndex = 2;
            this.waveViewer1.WaveStream = null;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.Bisque;
            this.label1.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.label1.Font = new System.Drawing.Font("Century Gothic", 14.25F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.Peru;
            this.label1.Location = new System.Drawing.Point(0, 75);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(99, 23);
            this.label1.TabIndex = 0;
            this.label1.Text = "CLIP VIEW";
            // 
            // panel2
            // 
            this.panel2.BackColor = System.Drawing.Color.Pink;
            this.panel2.Controls.Add(this.btn_RECSTOP);
            this.panel2.Controls.Add(this.cmb_InputsList);
            this.panel2.Controls.Add(this.lbl_REC_Audio);
            this.panel2.Location = new System.Drawing.Point(611, 130);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(164, 109);
            this.panel2.TabIndex = 8;
            // 
            // btn_RECSTOP
            // 
            this.btn_RECSTOP.BackColor = System.Drawing.Color.LightCoral;
            this.btn_RECSTOP.Location = new System.Drawing.Point(15, 60);
            this.btn_RECSTOP.Name = "btn_RECSTOP";
            this.btn_RECSTOP.Size = new System.Drawing.Size(130, 23);
            this.btn_RECSTOP.TabIndex = 2;
            this.btn_RECSTOP.Text = "REC";
            this.btn_RECSTOP.UseVisualStyleBackColor = false;
            this.btn_RECSTOP.Click += new System.EventHandler(this.btn_RECSTOP_Click);
            // 
            // cmb_InputsList
            // 
            this.cmb_InputsList.FormattingEnabled = true;
            this.cmb_InputsList.Location = new System.Drawing.Point(8, 30);
            this.cmb_InputsList.Name = "cmb_InputsList";
            this.cmb_InputsList.Size = new System.Drawing.Size(152, 21);
            this.cmb_InputsList.TabIndex = 1;
            this.cmb_InputsList.Text = "Input Selection";
            this.cmb_InputsList.Click += new System.EventHandler(this.cmb_InputsList_Click);
            // 
            // lbl_REC_Audio
            // 
            this.lbl_REC_Audio.AutoSize = true;
            this.lbl_REC_Audio.Cursor = System.Windows.Forms.Cursors.Default;
            this.lbl_REC_Audio.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.lbl_REC_Audio.Font = new System.Drawing.Font("Century Gothic", 13F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_REC_Audio.ForeColor = System.Drawing.Color.Crimson;
            this.lbl_REC_Audio.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.lbl_REC_Audio.Location = new System.Drawing.Point(0, 87);
            this.lbl_REC_Audio.Margin = new System.Windows.Forms.Padding(0);
            this.lbl_REC_Audio.Name = "lbl_REC_Audio";
            this.lbl_REC_Audio.Size = new System.Drawing.Size(161, 22);
            this.lbl_REC_Audio.TabIndex = 0;
            this.lbl_REC_Audio.Text = "REC AUDIO MENU";
            this.lbl_REC_Audio.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // panel3
            // 
            this.panel3.BackColor = System.Drawing.Color.PaleTurquoise;
            this.panel3.Controls.Add(this.btn_MIDI_PLAY);
            this.panel3.Controls.Add(this.btn_MIDI_RECSTOP);
            this.panel3.Controls.Add(this.cmb_MIDI_InList);
            this.panel3.Controls.Add(this.cmb_MIDI_FileList);
            this.panel3.Controls.Add(this.lbl_MIDI);
            this.panel3.Location = new System.Drawing.Point(615, 245);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(160, 176);
            this.panel3.TabIndex = 9;
            // 
            // btn_MIDI_PLAY
            // 
            this.btn_MIDI_PLAY.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.btn_MIDI_PLAY.Location = new System.Drawing.Point(11, 125);
            this.btn_MIDI_PLAY.Name = "btn_MIDI_PLAY";
            this.btn_MIDI_PLAY.Size = new System.Drawing.Size(130, 23);
            this.btn_MIDI_PLAY.TabIndex = 2;
            this.btn_MIDI_PLAY.Text = "PLAY";
            this.btn_MIDI_PLAY.UseVisualStyleBackColor = false;
            this.btn_MIDI_PLAY.Click += new System.EventHandler(this.btn_RECSTOP_Click);
            // 
            // btn_MIDI_RECSTOP
            // 
            this.btn_MIDI_RECSTOP.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.btn_MIDI_RECSTOP.Location = new System.Drawing.Point(11, 40);
            this.btn_MIDI_RECSTOP.Name = "btn_MIDI_RECSTOP";
            this.btn_MIDI_RECSTOP.Size = new System.Drawing.Size(130, 23);
            this.btn_MIDI_RECSTOP.TabIndex = 2;
            this.btn_MIDI_RECSTOP.Text = "REC";
            this.btn_MIDI_RECSTOP.UseVisualStyleBackColor = false;
            this.btn_MIDI_RECSTOP.Click += new System.EventHandler(this.btn_MIDI_RECSTOP_Click);
            // 
            // cmb_MIDI_FileList
            // 
            this.cmb_MIDI_FileList.FormattingEnabled = true;
            this.cmb_MIDI_FileList.Location = new System.Drawing.Point(4, 97);
            this.cmb_MIDI_FileList.Name = "cmb_MIDI_FileList";
            this.cmb_MIDI_FileList.Size = new System.Drawing.Size(152, 21);
            this.cmb_MIDI_FileList.TabIndex = 1;
            this.cmb_MIDI_FileList.Text = "Select MIDI File for Playing";
            this.cmb_MIDI_FileList.Click += new System.EventHandler(this.cmb_MIDI_FileList_Click);
            // 
            // lbl_MIDI
            // 
            this.lbl_MIDI.AutoSize = true;
            this.lbl_MIDI.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.lbl_MIDI.Font = new System.Drawing.Font("Century Gothic", 12.75F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_MIDI.ForeColor = System.Drawing.Color.Teal;
            this.lbl_MIDI.Location = new System.Drawing.Point(0, 155);
            this.lbl_MIDI.Name = "lbl_MIDI";
            this.lbl_MIDI.Size = new System.Drawing.Size(100, 21);
            this.lbl_MIDI.TabIndex = 0;
            this.lbl_MIDI.Text = "MIDI MENU";
            // 
            // cmb_MIDI_InList
            // 
            this.cmb_MIDI_InList.FormattingEnabled = true;
            this.cmb_MIDI_InList.Location = new System.Drawing.Point(3, 13);
            this.cmb_MIDI_InList.Name = "cmb_MIDI_InList";
            this.cmb_MIDI_InList.Size = new System.Drawing.Size(152, 21);
            this.cmb_MIDI_InList.TabIndex = 1;
            this.cmb_MIDI_InList.Text = "Select MIDI In Device";
            this.cmb_MIDI_InList.Click += new System.EventHandler(this.cmb_MIDI_InList_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.panel3);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.btn_KP3Toggle);
            this.Controls.Add(this.btn_KP2Toggle);
            this.Controls.Add(this.btn_KP6Toggle);
            this.Controls.Add(this.btn_KP5Toggle);
            this.Controls.Add(this.btn_KP1Toggle);
            this.Controls.Add(this.btn_KP9Toggle);
            this.Controls.Add(this.btn_KP4Toggle);
            this.Controls.Add(this.btn_KP8Toggle);
            this.Controls.Add(this.btn_KP7Toggle);
            this.Controls.Add(this.txt_KP3file);
            this.Controls.Add(this.txt_KP2file);
            this.Controls.Add(this.txt_KP6file);
            this.Controls.Add(this.txt_KP5file);
            this.Controls.Add(this.txt_KP1file);
            this.Controls.Add(this.txt_KP9file);
            this.Controls.Add(this.txt_KP4file);
            this.Controls.Add(this.txt_KP8file);
            this.Controls.Add(this.txt_KP7file);
            this.Controls.Add(this.lbl_KP3);
            this.Controls.Add(this.lbl_KP2);
            this.Controls.Add(this.lbl_KP6);
            this.Controls.Add(this.lbl_KP5);
            this.Controls.Add(this.lbl_KP1);
            this.Controls.Add(this.lbl_KP9);
            this.Controls.Add(this.lbl_KP4);
            this.Controls.Add(this.lbl_KP8);
            this.Controls.Add(this.lbl_KP7);
            this.Controls.Add(this.btn_addsamples);
            this.Controls.Add(this.lst_samplelist);
            this.KeyPreview = true;
            this.Name = "Form1";
            this.Text = "Form1";
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyDown);
            this.KeyUp += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyUp);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.panel3.ResumeLayout(false);
            this.panel3.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.ListBox lst_samplelist;
        private System.Windows.Forms.Button btn_addsamples;
        private System.Windows.Forms.Label lbl_KP7;
        private System.Windows.Forms.Label lbl_KP8;
        private System.Windows.Forms.Label lbl_KP9;
        private System.Windows.Forms.Label lbl_KP4;
        private System.Windows.Forms.Label lbl_KP5;
        private System.Windows.Forms.Label lbl_KP6;
        private System.Windows.Forms.Label lbl_KP1;
        private System.Windows.Forms.Label lbl_KP2;
        private System.Windows.Forms.Label lbl_KP3;
        private System.Windows.Forms.TextBox txt_KP7file;
        private System.Windows.Forms.TextBox txt_KP8file;
        private System.Windows.Forms.TextBox txt_KP9file;
        private System.Windows.Forms.TextBox txt_KP4file;
        private System.Windows.Forms.TextBox txt_KP5file;
        private System.Windows.Forms.TextBox txt_KP6file;
        private System.Windows.Forms.TextBox txt_KP1file;
        private System.Windows.Forms.TextBox txt_KP2file;
        private System.Windows.Forms.TextBox txt_KP3file;
        private System.Windows.Forms.Button btn_KP7Toggle;
        private System.Windows.Forms.Button btn_KP8Toggle;
        private System.Windows.Forms.Button btn_KP9Toggle;
        private System.Windows.Forms.Button btn_KP4Toggle;
        private System.Windows.Forms.Button btn_KP5Toggle;
        private System.Windows.Forms.Button btn_KP6Toggle;
        private System.Windows.Forms.Button btn_KP1Toggle;
        private System.Windows.Forms.Button btn_KP2Toggle;
        private System.Windows.Forms.Button btn_KP3Toggle;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label lbl_REC_Audio;
        private System.Windows.Forms.ComboBox cmb_InputsList;
        private System.Windows.Forms.Button btn_RECSTOP;
        private NAudio.Gui.WaveViewer waveViewer;
        private NAudio.Gui.WaveViewer waveViewer1;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.Button btn_MIDI_RECSTOP;
        private System.Windows.Forms.ComboBox cmb_MIDI_FileList;
        private System.Windows.Forms.Label lbl_MIDI;
        private System.Windows.Forms.Button btn_MIDI_PLAY;
        private System.Windows.Forms.ComboBox cmb_MIDI_InList;
    }
}

