
namespace Spotkaniav2
{
    partial class Dodaj
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
            this.t_imie = new System.Windows.Forms.TextBox();
            this.t_nazwisko = new System.Windows.Forms.TextBox();
            this.l_imie = new System.Windows.Forms.Label();
            this.l_nazwisko = new System.Windows.Forms.Label();
            this.b_dodaj = new System.Windows.Forms.Button();
            this.b_anuluj = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // t_imie
            // 
            this.t_imie.Location = new System.Drawing.Point(78, 12);
            this.t_imie.Name = "t_imie";
            this.t_imie.Size = new System.Drawing.Size(218, 23);
            this.t_imie.TabIndex = 0;
            // 
            // t_nazwisko
            // 
            this.t_nazwisko.Location = new System.Drawing.Point(78, 49);
            this.t_nazwisko.Name = "t_nazwisko";
            this.t_nazwisko.Size = new System.Drawing.Size(218, 23);
            this.t_nazwisko.TabIndex = 1;
            // 
            // l_imie
            // 
            this.l_imie.AutoSize = true;
            this.l_imie.Location = new System.Drawing.Point(12, 15);
            this.l_imie.Name = "l_imie";
            this.l_imie.Size = new System.Drawing.Size(33, 15);
            this.l_imie.TabIndex = 2;
            this.l_imie.Text = "Imie:";
            // 
            // l_nazwisko
            // 
            this.l_nazwisko.AutoSize = true;
            this.l_nazwisko.Location = new System.Drawing.Point(12, 52);
            this.l_nazwisko.Name = "l_nazwisko";
            this.l_nazwisko.Size = new System.Drawing.Size(60, 15);
            this.l_nazwisko.TabIndex = 3;
            this.l_nazwisko.Text = "Nazwisko:";
            // 
            // b_dodaj
            // 
            this.b_dodaj.Location = new System.Drawing.Point(12, 91);
            this.b_dodaj.Name = "b_dodaj";
            this.b_dodaj.Size = new System.Drawing.Size(139, 23);
            this.b_dodaj.TabIndex = 4;
            this.b_dodaj.Text = "Dodaj";
            this.b_dodaj.UseVisualStyleBackColor = true;
            this.b_dodaj.Click += new System.EventHandler(this.b_dodaj_Click);
            // 
            // b_anuluj
            // 
            this.b_anuluj.Location = new System.Drawing.Point(157, 91);
            this.b_anuluj.Name = "b_anuluj";
            this.b_anuluj.Size = new System.Drawing.Size(139, 23);
            this.b_anuluj.TabIndex = 5;
            this.b_anuluj.Text = "Anuluj";
            this.b_anuluj.UseVisualStyleBackColor = true;
            this.b_anuluj.Click += new System.EventHandler(this.b_anuluj_Click);
            // 
            // Dodaj
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(306, 125);
            this.Controls.Add(this.b_anuluj);
            this.Controls.Add(this.b_dodaj);
            this.Controls.Add(this.l_nazwisko);
            this.Controls.Add(this.l_imie);
            this.Controls.Add(this.t_nazwisko);
            this.Controls.Add(this.t_imie);
            this.Name = "Dodaj";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Zarządzenie spotkaniami";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox t_imie;
        private System.Windows.Forms.TextBox t_nazwisko;
        private System.Windows.Forms.Label l_imie;
        private System.Windows.Forms.Label l_nazwisko;
        private System.Windows.Forms.Button b_dodaj;
        private System.Windows.Forms.Button b_anuluj;
    }
}