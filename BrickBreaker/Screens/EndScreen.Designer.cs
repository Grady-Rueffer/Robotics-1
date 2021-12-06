
namespace BrickBreaker
{
    partial class EndScreen
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(EndScreen));
            this.gameoverLabel = new System.Windows.Forms.Label();
            this.retryLevel = new System.Windows.Forms.Button();
            this.menuButton = new System.Windows.Forms.Button();
            this.exitButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // gameoverLabel
            // 
            this.gameoverLabel.BackColor = System.Drawing.Color.Transparent;
            this.gameoverLabel.Font = new System.Drawing.Font("Ink Free", 72F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gameoverLabel.ForeColor = System.Drawing.Color.White;
            this.gameoverLabel.Location = new System.Drawing.Point(65, 58);
            this.gameoverLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.gameoverLabel.Name = "gameoverLabel";
            this.gameoverLabel.Size = new System.Drawing.Size(941, 254);
            this.gameoverLabel.TabIndex = 0;
            this.gameoverLabel.Text = "Game Over";
            this.gameoverLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // retryLevel
            // 
            this.retryLevel.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("retryLevel.BackgroundImage")));
            this.retryLevel.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.retryLevel.FlatAppearance.BorderSize = 5;
            this.retryLevel.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.retryLevel.Font = new System.Drawing.Font("Ink Free", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.retryLevel.ForeColor = System.Drawing.Color.White;
            this.retryLevel.Location = new System.Drawing.Point(132, 288);
            this.retryLevel.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.retryLevel.Name = "retryLevel";
            this.retryLevel.Size = new System.Drawing.Size(247, 101);
            this.retryLevel.TabIndex = 1;
            this.retryLevel.Text = "Retry";
            this.retryLevel.UseVisualStyleBackColor = true;
            this.retryLevel.Click += new System.EventHandler(this.retryLevel_Click);
            // 
            // menuButton
            // 
            this.menuButton.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("menuButton.BackgroundImage")));
            this.menuButton.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.menuButton.FlatAppearance.BorderSize = 5;
            this.menuButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.menuButton.Font = new System.Drawing.Font("Ink Free", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.menuButton.ForeColor = System.Drawing.Color.White;
            this.menuButton.Location = new System.Drawing.Point(417, 288);
            this.menuButton.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.menuButton.Name = "menuButton";
            this.menuButton.Size = new System.Drawing.Size(247, 101);
            this.menuButton.TabIndex = 2;
            this.menuButton.Text = "Main Menu";
            this.menuButton.UseVisualStyleBackColor = true;
            this.menuButton.Click += new System.EventHandler(this.menuButton_Click);
            // 
            // exitButton
            // 
            this.exitButton.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("exitButton.BackgroundImage")));
            this.exitButton.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.exitButton.FlatAppearance.BorderSize = 5;
            this.exitButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.exitButton.Font = new System.Drawing.Font("Ink Free", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.exitButton.ForeColor = System.Drawing.Color.White;
            this.exitButton.Location = new System.Drawing.Point(713, 288);
            this.exitButton.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.exitButton.Name = "exitButton";
            this.exitButton.Size = new System.Drawing.Size(247, 101);
            this.exitButton.TabIndex = 3;
            this.exitButton.Text = "Exit";
            this.exitButton.UseVisualStyleBackColor = true;
            this.exitButton.Click += new System.EventHandler(this.exitButton_Click);
            // 
            // EndScreen
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.Controls.Add(this.exitButton);
            this.Controls.Add(this.menuButton);
            this.Controls.Add(this.retryLevel);
            this.Controls.Add(this.gameoverLabel);
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "EndScreen";
            this.Size = new System.Drawing.Size(1100, 700);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label gameoverLabel;
        private System.Windows.Forms.Button retryLevel;
        private System.Windows.Forms.Button menuButton;
        private System.Windows.Forms.Button exitButton;
    }
}
