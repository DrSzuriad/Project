
namespace Spotkaniav2
{
    partial class Utworz
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
            this.l_nazwa = new System.Windows.Forms.Label();
            this.l_opis = new System.Windows.Forms.Label();
            this.t_nazwa = new System.Windows.Forms.TextBox();
            this.t_opis = new System.Windows.Forms.TextBox();
            this.l_data_spotkania = new System.Windows.Forms.Label();
            this.k_data_spotkania = new System.Windows.Forms.MonthCalendar();
            this.b_dodaj = new System.Windows.Forms.Button();
            this.b_anuluj = new System.Windows.Forms.Button();
            this.k_godzina_spotkania = new System.Windows.Forms.DateTimePicker();
            this.SuspendLayout();
            // 
            // l_nazwa
            // 
            this.l_nazwa.AutoSize = true;
            this.l_nazwa.Location = new System.Drawing.Point(12, 15);
            this.l_nazwa.Name = "l_nazwa";
            this.l_nazwa.Size = new System.Drawing.Size(45, 15);
            this.l_nazwa.TabIndex = 0;
            this.l_nazwa.Text = "Nazwa:";
            // 
            // l_opis
            // 
            this.l_opis.AutoSize = true;
            this.l_opis.Location = new System.Drawing.Point(12, 52);
            this.l_opis.Name = "l_opis";
            this.l_opis.Size = new System.Drawing.Size(34, 15);
            this.l_opis.TabIndex = 3;
            this.l_opis.Text = "Opis:";
            // 
            // t_nazwa
            // 
            this.t_nazwa.Location = new System.Drawing.Point(63, 12);
            this.t_nazwa.Name = "t_nazwa";
            this.t_nazwa.PlaceholderText = "Nazwa";
            this.t_nazwa.Size = new System.Drawing.Size(218, 23);
            this.t_nazwa.TabIndex = 4;
            // 
            // t_opis
            // 
            this.t_opis.Location = new System.Drawing.Point(63, 49);
            this.t_opis.MinimumSize = new System.Drawing.Size(4, 100);
            this.t_opis.Multiline = true;
            this.t_opis.Name = "t_opis";
            this.t_opis.PlaceholderText = "Opis";
            this.t_opis.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.t_opis.Size = new System.Drawing.Size(218, 100);
            this.t_opis.TabIndex = 5;
            // 
            // l_data_spotkania
            // 
            this.l_data_spotkania.AutoSize = true;
            this.l_data_spotkania.Location = new System.Drawing.Point(44, 170);
            this.l_data_spotkania.Name = "l_data_spotkania";
            this.l_data_spotkania.Size = new System.Drawing.Size(88, 15);
            this.l_data_spotkania.TabIndex = 6;
            this.l_data_spotkania.Text = "Data spotkania:";
            // 
            // k_data_spotkania
            // 
            this.k_data_spotkania.Location = new System.Drawing.Point(12, 192);
            this.k_data_spotkania.MaxSelectionCount = 1;
            this.k_data_spotkania.Name = "k_data_spotkania";
            this.k_data_spotkania.TabIndex = 7;
            // 
            // b_dodaj
            // 
            this.b_dodaj.Location = new System.Drawing.Point(12, 366);
            this.b_dodaj.Name = "b_dodaj";
            this.b_dodaj.Size = new System.Drawing.Size(130, 23);
            this.b_dodaj.TabIndex = 8;
            this.b_dodaj.Text = "Dodaj";
            this.b_dodaj.UseVisualStyleBackColor = true;
            this.b_dodaj.Click += new System.EventHandler(this.b_dodaj_Click);
            // 
            // b_anuluj
            // 
            this.b_anuluj.Location = new System.Drawing.Point(151, 366);
            this.b_anuluj.Name = "b_anuluj";
            this.b_anuluj.Size = new System.Drawing.Size(130, 23);
            this.b_anuluj.TabIndex = 9;
            this.b_anuluj.Text = "Anuluj";
            this.b_anuluj.UseVisualStyleBackColor = true;
            this.b_anuluj.Click += new System.EventHandler(this.b_anuluj_Click);
            // 
            // k_godzina_spotkania
            // 
            this.k_godzina_spotkania.AllowDrop = true;
            this.k_godzina_spotkania.Checked = false;
            this.k_godzina_spotkania.Format = System.Windows.Forms.DateTimePickerFormat.Time;
            this.k_godzina_spotkania.Location = new System.Drawing.Point(163, 164);
            this.k_godzina_spotkania.Name = "k_godzina_spotkania";
            this.k_godzina_spotkania.ShowUpDown = true;
            this.k_godzina_spotkania.Size = new System.Drawing.Size(67, 23);
            this.k_godzina_spotkania.TabIndex = 10;
            // 
            // Utworz
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(296, 402);
            this.Controls.Add(this.k_godzina_spotkania);
            this.Controls.Add(this.b_anuluj);
            this.Controls.Add(this.b_dodaj);
            this.Controls.Add(this.k_data_spotkania);
            this.Controls.Add(this.l_data_spotkania);
            this.Controls.Add(this.t_opis);
            this.Controls.Add(this.t_nazwa);
            this.Controls.Add(this.l_opis);
            this.Controls.Add(this.l_nazwa);
            this.MaximumSize = new System.Drawing.Size(312, 441);
            this.MinimumSize = new System.Drawing.Size(312, 441);
            this.Name = "Utworz";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Zarządzenie spotkaniami";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label l_nazwa;
        private System.Windows.Forms.Label l_opis;
        private System.Windows.Forms.TextBox t_nazwa;
        private System.Windows.Forms.TextBox t_opis;
        private System.Windows.Forms.Label l_data_spotkania;
        private System.Windows.Forms.MonthCalendar k_data_spotkania;
        private System.Windows.Forms.Button b_dodaj;
        private System.Windows.Forms.Button b_anuluj;
        private System.Windows.Forms.DateTimePicker k_godzina_spotkania;
    }
}