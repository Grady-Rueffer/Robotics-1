namespace BrickBreaker
{
    partial class GameScreen
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

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.gameTimer = new System.Windows.Forms.Timer(this.components);
            this.testLabel = new System.Windows.Forms.Label();
            this.pUpLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // gameTimer
            // 
            this.gameTimer.Enabled = true;
            this.gameTimer.Interval = 1;
            this.gameTimer.Tick += new System.EventHandler(this.gameTimer_Tick);
            // 
            // testLabel
            // 
            this.testLabel.AutoSize = true;
            this.testLabel.BackColor = System.Drawing.Color.White;
            this.testLabel.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.testLabel.Location = new System.Drawing.Point(4, 4);
            this.testLabel.Name = "testLabel";
            this.testLabel.Size = new System.Drawing.Size(178, 13);
            this.testLabel.TabIndex = 0;
            this.testLabel.Text = "test Label (NOT FOR FINAL BUILD)";
            // 
            // pUpLabel
            // 
            this.pUpLabel.Location = new System.Drawing.Point(3, 9);
            this.pUpLabel.Name = "pUpLabel";
            this.pUpLabel.Size = new System.Drawing.Size(171, 102);
            this.pUpLabel.TabIndex = 0;
            this.pUpLabel.Text = "label1";
            // 
            // GameScreen
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(96F, 96F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Dpi;
            this.BackColor = System.Drawing.Color.Turquoise;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.Controls.Add(this.pUpLabel);
            this.DoubleBuffered = true;
            this.Name = "GameScreen";
            this.Size = new System.Drawing.Size(880, 560);
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.GameScreen_Paint);
            this.KeyUp += new System.Windows.Forms.KeyEventHandler(this.GameScreen_KeyUp);
            this.PreviewKeyDown += new System.Windows.Forms.PreviewKeyDownEventHandler(this.GameScreen_PreviewKeyDown);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Timer gameTimer;
        private System.Windows.Forms.Label testLabel;
        private System.Windows.Forms.Label pUpLabel;
    }
}
