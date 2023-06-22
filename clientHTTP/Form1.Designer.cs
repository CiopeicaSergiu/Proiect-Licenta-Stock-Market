namespace clientHTTP
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
            this._getStockButton = new System.Windows.Forms.Button();
            this._startTextBox = new System.Windows.Forms.TextBox();
            this._stopTextBox = new System.Windows.Forms.TextBox();
            this._stockName = new System.Windows.Forms.TextBox();
            this._stockNameLabel = new System.Windows.Forms.Label();
            this._startTimeLabel = new System.Windows.Forms.Label();
            this._endTimeLabel = new System.Windows.Forms.Label();
            this._dataGridViewStockData = new System.Windows.Forms.DataGridView();
            ((System.ComponentModel.ISupportInitialize)(this._dataGridViewStockData)).BeginInit();
            this.SuspendLayout();
            // 
            // _getStockButton
            // 
            this._getStockButton.Location = new System.Drawing.Point(610, 674);
            this._getStockButton.Name = "_getStockButton";
            this._getStockButton.Size = new System.Drawing.Size(100, 38);
            this._getStockButton.TabIndex = 0;
            this._getStockButton.Text = "goog";
            this._getStockButton.UseVisualStyleBackColor = true;
            this._getStockButton.Click += new System.EventHandler(this.getGoogStockData);
            // 
            // _startTextBox
            // 
            this._startTextBox.Location = new System.Drawing.Point(1366, 601);
            this._startTextBox.Name = "_startTextBox";
            this._startTextBox.Size = new System.Drawing.Size(100, 20);
            this._startTextBox.TabIndex = 2;
            // 
            // _stopTextBox
            // 
            this._stopTextBox.Location = new System.Drawing.Point(1366, 648);
            this._stopTextBox.Name = "_stopTextBox";
            this._stopTextBox.Size = new System.Drawing.Size(100, 20);
            this._stopTextBox.TabIndex = 3;
            // 
            // _stockName
            // 
            this._stockName.Location = new System.Drawing.Point(1366, 556);
            this._stockName.Name = "_stockName";
            this._stockName.Size = new System.Drawing.Size(100, 20);
            this._stockName.TabIndex = 4;
            // 
            // _stockNameLabel
            // 
            this._stockNameLabel.AutoSize = true;
            this._stockNameLabel.Location = new System.Drawing.Point(1295, 556);
            this._stockNameLabel.Name = "_stockNameLabel";
            this._stockNameLabel.Size = new System.Drawing.Size(66, 13);
            this._stockNameLabel.TabIndex = 6;
            this._stockNameLabel.Text = "Stock Name";
            // 
            // _startTimeLabel
            // 
            this._startTimeLabel.AutoSize = true;
            this._startTimeLabel.Location = new System.Drawing.Point(1295, 601);
            this._startTimeLabel.Name = "_startTimeLabel";
            this._startTimeLabel.Size = new System.Drawing.Size(62, 13);
            this._startTimeLabel.TabIndex = 7;
            this._startTimeLabel.Text = "Start Period";
            // 
            // _endTimeLabel
            // 
            this._endTimeLabel.AutoSize = true;
            this._endTimeLabel.Location = new System.Drawing.Point(1295, 648);
            this._endTimeLabel.Name = "_endTimeLabel";
            this._endTimeLabel.Size = new System.Drawing.Size(59, 13);
            this._endTimeLabel.TabIndex = 8;
            this._endTimeLabel.Text = "End Period";
            // 
            // _dataGridViewStockData
            // 
            this._dataGridViewStockData.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this._dataGridViewStockData.Location = new System.Drawing.Point(116, 12);
            this._dataGridViewStockData.Name = "_dataGridViewStockData";
            this._dataGridViewStockData.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this._dataGridViewStockData.Size = new System.Drawing.Size(1086, 522);
            this._dataGridViewStockData.TabIndex = 9;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1584, 761);
            this.Controls.Add(this._dataGridViewStockData);
            this.Controls.Add(this._endTimeLabel);
            this.Controls.Add(this._startTimeLabel);
            this.Controls.Add(this._stockNameLabel);
            this.Controls.Add(this._stockName);
            this.Controls.Add(this._stopTextBox);
            this.Controls.Add(this._startTextBox);
            this.Controls.Add(this._getStockButton);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this._dataGridViewStockData)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button _getStockButton;
        private System.Windows.Forms.TextBox _startTextBox;
        private System.Windows.Forms.TextBox _stopTextBox;
        private System.Windows.Forms.TextBox _stockName;
        private System.Windows.Forms.Label _stockNameLabel;
        private System.Windows.Forms.Label _startTimeLabel;
        private System.Windows.Forms.Label _endTimeLabel;
        private System.Windows.Forms.DataGridView _dataGridViewStockData;
    }
}

