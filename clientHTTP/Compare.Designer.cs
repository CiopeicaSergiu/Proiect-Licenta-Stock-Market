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
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea4 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend7 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Legend legend8 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series7 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Series series8 = new System.Windows.Forms.DataVisualization.Charting.Series();
            this._compareA = new System.Windows.Forms.ComboBox();
            this._compareB = new System.Windows.Forms.ComboBox();
            this._addStockTextBox = new System.Windows.Forms.TextBox();
            this._addButton = new System.Windows.Forms.Button();
            this._compareChart = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this._startingDate = new System.Windows.Forms.TextBox();
            this._endingDate = new System.Windows.Forms.TextBox();
            this._compareButton = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this._compareChart)).BeginInit();
            this.SuspendLayout();
            // 
            // _compareA
            // 
            this._compareA.FormattingEnabled = true;
            this._compareA.Location = new System.Drawing.Point(28, 96);
            this._compareA.Name = "_compareA";
            this._compareA.Size = new System.Drawing.Size(121, 21);
            this._compareA.TabIndex = 0;
            // 
            // _compareB
            // 
            this._compareB.FormattingEnabled = true;
            this._compareB.Location = new System.Drawing.Point(28, 134);
            this._compareB.Name = "_compareB";
            this._compareB.Size = new System.Drawing.Size(121, 21);
            this._compareB.TabIndex = 1;
            // 
            // _addStockTextBox
            // 
            this._addStockTextBox.Location = new System.Drawing.Point(184, 59);
            this._addStockTextBox.Name = "_addStockTextBox";
            this._addStockTextBox.Size = new System.Drawing.Size(100, 20);
            this._addStockTextBox.TabIndex = 3;
            // 
            // _addButton
            // 
            this._addButton.Location = new System.Drawing.Point(28, 56);
            this._addButton.Name = "_addButton";
            this._addButton.Size = new System.Drawing.Size(75, 23);
            this._addButton.TabIndex = 4;
            this._addButton.Text = "Add";
            this._addButton.UseVisualStyleBackColor = true;
            this._addButton.Click += new System.EventHandler(this.addStockForCompare);
            // 
            // _compareChart
            // 
            chartArea4.Name = "ChartArea1";
            this._compareChart.ChartAreas.Add(chartArea4);
            legend7.Name = "StockA";
            legend8.Name = "StockB";
            this._compareChart.Legends.Add(legend7);
            this._compareChart.Legends.Add(legend8);
            this._compareChart.Location = new System.Drawing.Point(320, 30);
            this._compareChart.Name = "_compareChart";
            series7.ChartArea = "ChartArea1";
            series7.Legend = "StockA";
            series7.Name = "StockA";
            series8.ChartArea = "ChartArea1";
            series8.Legend = "StockA";
            series8.Name = "StockB";
            this._compareChart.Series.Add(series7);
            this._compareChart.Series.Add(series8);
            this._compareChart.Size = new System.Drawing.Size(960, 561);
            this._compareChart.TabIndex = 5;
            this._compareChart.Text = "Compare Stocks";
            // 
            // _startingDate
            // 
            this._startingDate.Location = new System.Drawing.Point(184, 96);
            this._startingDate.Name = "_startingDate";
            this._startingDate.Size = new System.Drawing.Size(100, 20);
            this._startingDate.TabIndex = 6;
            // 
            // _endingDate
            // 
            this._endingDate.Location = new System.Drawing.Point(184, 135);
            this._endingDate.Name = "_endingDate";
            this._endingDate.Size = new System.Drawing.Size(100, 20);
            this._endingDate.TabIndex = 7;
            // 
            // _compareButton
            // 
            this._compareButton.Location = new System.Drawing.Point(28, 172);
            this._compareButton.Name = "_compareButton";
            this._compareButton.Size = new System.Drawing.Size(75, 23);
            this._compareButton.TabIndex = 8;
            this._compareButton.Text = "compare";
            this._compareButton.UseVisualStyleBackColor = true;
            this._compareButton.Click += new System.EventHandler(this.compareStocks);
            // 
            // Compare
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1292, 620);
            this.Controls.Add(this._compareButton);
            this.Controls.Add(this._endingDate);
            this.Controls.Add(this._startingDate);
            this.Controls.Add(this._compareChart);
            this.Controls.Add(this._addButton);
            this.Controls.Add(this._addStockTextBox);
            this.Controls.Add(this._compareB);
            this.Controls.Add(this._compareA);
            this.Name = "Compare";
            this.Text = "Compare";
            ((System.ComponentModel.ISupportInitialize)(this._compareChart)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox _compareA;
        private System.Windows.Forms.ComboBox _compareB;
        private System.Windows.Forms.TextBox _addStockTextBox;
        private System.Windows.Forms.Button _addButton;
        private System.Windows.Forms.DataVisualization.Charting.Chart _compareChart;
        private System.Windows.Forms.TextBox _startingDate;
        private System.Windows.Forms.TextBox _endingDate;
        private System.Windows.Forms.Button _compareButton;
    }
}