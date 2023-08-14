namespace clientHTTP
{
    partial class Compare
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
            this._compareA = new System.Windows.Forms.ComboBox();
            this._compareB = new System.Windows.Forms.ComboBox();
            this._stocksListBox = new System.Windows.Forms.ListBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this._addButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // _compareA
            // 
            this._compareA.FormattingEnabled = true;
            this._compareA.Location = new System.Drawing.Point(169, 30);
            this._compareA.Name = "_compareA";
            this._compareA.Size = new System.Drawing.Size(121, 21);
            this._compareA.TabIndex = 0;
            // 
            // _compareB
            // 
            this._compareB.FormattingEnabled = true;
            this._compareB.Location = new System.Drawing.Point(169, 68);
            this._compareB.Name = "_compareB";
            this._compareB.Size = new System.Drawing.Size(121, 21);
            this._compareB.TabIndex = 1;
            // 
            // _stocksListBox
            // 
            this._stocksListBox.FormattingEnabled = true;
            this._stocksListBox.Location = new System.Drawing.Point(170, 117);
            this._stocksListBox.Name = "_stocksListBox";
            this._stocksListBox.Size = new System.Drawing.Size(120, 95);
            this._stocksListBox.TabIndex = 2;
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(27, 31);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(100, 20);
            this.textBox1.TabIndex = 3;
            // 
            // _addButton
            // 
            this._addButton.Location = new System.Drawing.Point(38, 104);
            this._addButton.Name = "_addButton";
            this._addButton.Size = new System.Drawing.Size(75, 23);
            this._addButton.TabIndex = 4;
            this._addButton.Text = "Add";
            this._addButton.UseVisualStyleBackColor = true;
            // 
            // Compare
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1292, 620);
            this.Controls.Add(this._addButton);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this._stocksListBox);
            this.Controls.Add(this._compareB);
            this.Controls.Add(this._compareA);
            this.Name = "Compare";
            this.Text = "Compare";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox _compareA;
        private System.Windows.Forms.ComboBox _compareB;
        private System.Windows.Forms.ListBox _stocksListBox;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button _addButton;
    }
}