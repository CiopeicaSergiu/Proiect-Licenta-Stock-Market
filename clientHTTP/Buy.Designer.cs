namespace clientHTTP
{
    partial class Buy
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
            this._quantityTextBox = new System.Windows.Forms.TextBox();
            this._priceTextBox = new System.Windows.Forms.TextBox();
            this._quantityLabel = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this._buyButton = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this._securityTextBox = new System.Windows.Forms.TextBox();
            this._securityLabel = new System.Windows.Forms.Label();
            this._tableBid = new System.Windows.Forms.DataGridView();
            this._tableAsk = new System.Windows.Forms.DataGridView();
            this._deleteCommand = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this._tableBid)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this._tableAsk)).BeginInit();
            this.SuspendLayout();
            // 
            // _quantityTextBox
            // 
            this._quantityTextBox.Location = new System.Drawing.Point(89, 121);
            this._quantityTextBox.Name = "_quantityTextBox";
            this._quantityTextBox.Size = new System.Drawing.Size(100, 20);
            this._quantityTextBox.TabIndex = 0;
            // 
            // _priceTextBox
            // 
            this._priceTextBox.Location = new System.Drawing.Point(89, 158);
            this._priceTextBox.Name = "_priceTextBox";
            this._priceTextBox.Size = new System.Drawing.Size(100, 20);
            this._priceTextBox.TabIndex = 1;
            // 
            // _quantityLabel
            // 
            this._quantityLabel.AutoSize = true;
            this._quantityLabel.Location = new System.Drawing.Point(25, 124);
            this._quantityLabel.Name = "_quantityLabel";
            this._quantityLabel.Size = new System.Drawing.Size(46, 13);
            this._quantityLabel.TabIndex = 2;
            this._quantityLabel.Text = "Quantity";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(28, 164);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(31, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Price";
            // 
            // _buyButton
            // 
            this._buyButton.Location = new System.Drawing.Point(89, 195);
            this._buyButton.Name = "_buyButton";
            this._buyButton.Size = new System.Drawing.Size(100, 32);
            this._buyButton.TabIndex = 4;
            this._buyButton.Text = "Command Stock";
            this._buyButton.UseVisualStyleBackColor = true;
            this._buyButton.Click += new System.EventHandler(this.putStockCommand);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(226, 39);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(22, 13);
            this.label3.TabIndex = 7;
            this.label3.Text = "Bid";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(226, 353);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(25, 13);
            this.label4.TabIndex = 8;
            this.label4.Text = "Ask";
            // 
            // _securityTextBox
            // 
            this._securityTextBox.Location = new System.Drawing.Point(89, 78);
            this._securityTextBox.Name = "_securityTextBox";
            this._securityTextBox.Size = new System.Drawing.Size(100, 20);
            this._securityTextBox.TabIndex = 9;
            // 
            // _securityLabel
            // 
            this._securityLabel.AutoSize = true;
            this._securityLabel.Location = new System.Drawing.Point(25, 85);
            this._securityLabel.Name = "_securityLabel";
            this._securityLabel.Size = new System.Drawing.Size(45, 13);
            this._securityLabel.TabIndex = 10;
            this._securityLabel.Text = "Security";
            // 
            // _tableBid
            // 
            this._tableBid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this._tableBid.Location = new System.Drawing.Point(201, 55);
            this._tableBid.Name = "_tableBid";
            this._tableBid.Size = new System.Drawing.Size(1197, 274);
            this._tableBid.TabIndex = 11;
            this._tableBid.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.clickedCell);
            // 
            // _tableAsk
            // 
            this._tableAsk.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this._tableAsk.Location = new System.Drawing.Point(201, 369);
            this._tableAsk.Name = "_tableAsk";
            this._tableAsk.Size = new System.Drawing.Size(1197, 274);
            this._tableAsk.TabIndex = 12;
            // 
            // _deleteCommand
            // 
            this._deleteCommand.Location = new System.Drawing.Point(89, 233);
            this._deleteCommand.Name = "_deleteCommand";
            this._deleteCommand.Size = new System.Drawing.Size(100, 35);
            this._deleteCommand.TabIndex = 13;
            this._deleteCommand.Text = "Delete Command";
            this._deleteCommand.UseVisualStyleBackColor = true;
            this._deleteCommand.Click += new System.EventHandler(this.deleteCommand);
            // 
            // Buy
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1455, 843);
            this.Controls.Add(this._deleteCommand);
            this.Controls.Add(this._tableAsk);
            this.Controls.Add(this._tableBid);
            this.Controls.Add(this._securityLabel);
            this.Controls.Add(this._securityTextBox);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this._buyButton);
            this.Controls.Add(this.label2);
            this.Controls.Add(this._quantityLabel);
            this.Controls.Add(this._priceTextBox);
            this.Controls.Add(this._quantityTextBox);
            this.Name = "Buy";
            this.Text = "Buy";
            ((System.ComponentModel.ISupportInitialize)(this._tableBid)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this._tableAsk)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox _quantityTextBox;
        private System.Windows.Forms.TextBox _priceTextBox;
        private System.Windows.Forms.Label _quantityLabel;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button _buyButton;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox _securityTextBox;
        private System.Windows.Forms.Label _securityLabel;
        private System.Windows.Forms.DataGridView _tableBid;
        private System.Windows.Forms.DataGridView _tableAsk;
        private System.Windows.Forms.Button _deleteCommand;
    }
}