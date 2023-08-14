namespace clientHTTP
{
    partial class Login
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
            this._username = new System.Windows.Forms.TextBox();
            this._password = new System.Windows.Forms.TextBox();
            this._login = new System.Windows.Forms.Button();
            this._usernameLabel = new System.Windows.Forms.Label();
            this._passwordLabel = new System.Windows.Forms.Label();
            this._statusTextBox = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // _username
            // 
            this._username.Location = new System.Drawing.Point(460, 240);
            this._username.Multiline = true;
            this._username.Name = "_username";
            this._username.Size = new System.Drawing.Size(180, 20);
            this._username.TabIndex = 0;
            // 
            // _password
            // 
            this._password.Location = new System.Drawing.Point(460, 329);
            this._password.Name = "_password";
            this._password.Size = new System.Drawing.Size(180, 20);
            this._password.TabIndex = 1;
            // 
            // _login
            // 
            this._login.Location = new System.Drawing.Point(460, 383);
            this._login.Name = "_login";
            this._login.Size = new System.Drawing.Size(180, 38);
            this._login.TabIndex = 2;
            this._login.Text = "Login";
            this._login.UseVisualStyleBackColor = true;
            this._login.Click += new System.EventHandler(this.loginEvent);
            // 
            // _usernameLabel
            // 
            this._usernameLabel.AutoSize = true;
            this._usernameLabel.Location = new System.Drawing.Point(457, 212);
            this._usernameLabel.Name = "_usernameLabel";
            this._usernameLabel.Size = new System.Drawing.Size(53, 13);
            this._usernameLabel.TabIndex = 3;
            this._usernameLabel.Text = "username";
            // 
            // _passwordLabel
            // 
            this._passwordLabel.AutoSize = true;
            this._passwordLabel.Location = new System.Drawing.Point(457, 299);
            this._passwordLabel.Name = "_passwordLabel";
            this._passwordLabel.Size = new System.Drawing.Size(52, 13);
            this._passwordLabel.TabIndex = 4;
            this._passwordLabel.Text = "password";
            // 
            // _statusTextBox
            // 
            this._statusTextBox.Location = new System.Drawing.Point(460, 147);
            this._statusTextBox.Multiline = true;
            this._statusTextBox.Name = "_statusTextBox";
            this._statusTextBox.Size = new System.Drawing.Size(139, 36);
            this._statusTextBox.TabIndex = 5;
            // 
            // Login
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1132, 631);
            this.Controls.Add(this._statusTextBox);
            this.Controls.Add(this._passwordLabel);
            this.Controls.Add(this._usernameLabel);
            this.Controls.Add(this._login);
            this.Controls.Add(this._password);
            this.Controls.Add(this._username);
            this.Name = "Login";
            this.Text = "Login";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox _username;
        private System.Windows.Forms.TextBox _password;
        private System.Windows.Forms.Button _login;
        private System.Windows.Forms.Label _usernameLabel;
        private System.Windows.Forms.Label _passwordLabel;
        private System.Windows.Forms.TextBox _statusTextBox;
    }
}