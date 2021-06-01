
namespace Spotkaniav2
{
    partial class Lista
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
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle1 = new System.Windows.Forms.DataGridViewCellStyle();
            this.t_tablica = new System.Windows.Forms.DataGridView();
            this.b_utworz_spotkanie = new System.Windows.Forms.Button();
            this.b_usun_spotkanie = new System.Windows.Forms.Button();
            this.b_dodaj_uczestnika = new System.Windows.Forms.Button();
            this.b_lista_czestnikow = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.t_tablica)).BeginInit();
            this.SuspendLayout();
            // 
            // t_tablica
            // 
            this.t_tablica.AllowUserToAddRows = false;
            this.t_tablica.AllowUserToDeleteRows = false;
            this.t_tablica.AllowUserToResizeColumns = false;
            this.t_tablica.AllowUserToResizeRows = false;
            this.t_tablica.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridViewCellStyle1.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle1.BackColor = System.Drawing.SystemColors.Window;
            dataGridViewCellStyle1.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            dataGridViewCellStyle1.ForeColor = System.Drawing.SystemColors.ControlText;
            dataGridViewCellStyle1.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle1.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle1.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.t_tablica.DefaultCellStyle = dataGridViewCellStyle1;
            this.t_tablica.Location = new System.Drawing.Point(12, 12);
            this.t_tablica.MultiSelect = false;
            this.t_tablica.Name = "t_tablica";
            this.t_tablica.RowHeadersVisible = false;
            this.t_tablica.Size = new System.Drawing.Size(646, 350);
            this.t_tablica.TabIndex = 0;
            // 
            // b_utworz_spotkanie
            // 
            this.b_utworz_spotkanie.Location = new System.Drawing.Point(12, 372);
            this.b_utworz_spotkanie.Name = "b_utworz_spotkanie";
            this.b_utworz_spotkanie.Size = new System.Drawing.Size(157, 23);
            this.b_utworz_spotkanie.TabIndex = 2;
            this.b_utworz_spotkanie.Text = "Utworz spotkanie";
            this.b_utworz_spotkanie.UseVisualStyleBackColor = true;
            this.b_utworz_spotkanie.Click += new System.EventHandler(this.b_utworz_spotkanie_Click);
            // 
            // b_usun_spotkanie
            // 
            this.b_usun_spotkanie.Location = new System.Drawing.Point(175, 372);
            this.b_usun_spotkanie.Name = "b_usun_spotkanie";
            this.b_usun_spotkanie.Size = new System.Drawing.Size(157, 23);
            this.b_usun_spotkanie.TabIndex = 3;
            this.b_usun_spotkanie.Text = "Usuń spotkanie";
            this.b_usun_spotkanie.UseVisualStyleBackColor = true;
            this.b_usun_spotkanie.Click += new System.EventHandler(this.b_usun_spotkanie_Click);
            // 
            // b_dodaj_uczestnika
            // 
            this.b_dodaj_uczestnika.Location = new System.Drawing.Point(338, 372);
            this.b_dodaj_uczestnika.Name = "b_dodaj_uczestnika";
            this.b_dodaj_uczestnika.Size = new System.Drawing.Size(157, 23);
            this.b_dodaj_uczestnika.TabIndex = 4;
            this.b_dodaj_uczestnika.Text = "Dodaj uczestnika";
            this.b_dodaj_uczestnika.UseVisualStyleBackColor = true;
            this.b_dodaj_uczestnika.Click += new System.EventHandler(this.b_dodaj_uczestnika_Click);
            // 
            // b_lista_czestnikow
            // 
            this.b_lista_czestnikow.Location = new System.Drawing.Point(501, 372);
            this.b_lista_czestnikow.Name = "b_lista_czestnikow";
            this.b_lista_czestnikow.Size = new System.Drawing.Size(157, 23);
            this.b_lista_czestnikow.TabIndex = 5;
            this.b_lista_czestnikow.Text = "Zobacz uczestnikow";
            this.b_lista_czestnikow.UseVisualStyleBackColor = true;
            this.b_lista_czestnikow.Click += new System.EventHandler(this.b_lista_czestnikow_Click);
            // 
            // Lista
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(669, 403);
            this.Controls.Add(this.b_lista_czestnikow);
            this.Controls.Add(this.b_dodaj_uczestnika);
            this.Controls.Add(this.b_usun_spotkanie);
            this.Controls.Add(this.b_utworz_spotkanie);
            this.Controls.Add(this.t_tablica);
            this.MaximumSize = new System.Drawing.Size(685, 442);
            this.MinimumSize = new System.Drawing.Size(685, 442);
            this.Name = "Lista";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Zarządzenie spotkaniami";
            ((System.ComponentModel.ISupportInitialize)(this.t_tablica)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView t_tablica;
        private System.Windows.Forms.Button b_utworz_spotkanie;
        private System.Windows.Forms.Button b_usun_spotkanie;
        private System.Windows.Forms.Button b_dodaj_uczestnika;
        private System.Windows.Forms.Button b_lista_czestnikow;
    }
}