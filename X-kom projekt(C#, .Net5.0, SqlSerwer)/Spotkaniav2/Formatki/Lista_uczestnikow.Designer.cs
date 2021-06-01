
namespace Spotkaniav2
{
    partial class Lista_uczestnikow
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
            this.t_lista_uczestnikow = new System.Windows.Forms.DataGridView();
            this.b_usun = new System.Windows.Forms.Button();
            this.b_dodaj = new System.Windows.Forms.Button();
            this.b_wroc = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.t_lista_uczestnikow)).BeginInit();
            this.SuspendLayout();
            // 
            // t_lista_uczestnikow
            // 
            this.t_lista_uczestnikow.AllowUserToAddRows = false;
            this.t_lista_uczestnikow.AllowUserToDeleteRows = false;
            this.t_lista_uczestnikow.AllowUserToResizeColumns = false;
            this.t_lista_uczestnikow.AllowUserToResizeRows = false;
            this.t_lista_uczestnikow.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.t_lista_uczestnikow.Location = new System.Drawing.Point(12, 12);
            this.t_lista_uczestnikow.MultiSelect = false;
            this.t_lista_uczestnikow.Name = "t_lista_uczestnikow";
            this.t_lista_uczestnikow.RowHeadersVisible = false;
            this.t_lista_uczestnikow.RowTemplate.Height = 25;
            this.t_lista_uczestnikow.Size = new System.Drawing.Size(250, 252);
            this.t_lista_uczestnikow.TabIndex = 0;
            // 
            // b_usun
            // 
            this.b_usun.Location = new System.Drawing.Point(12, 275);
            this.b_usun.Name = "b_usun";
            this.b_usun.Size = new System.Drawing.Size(250, 23);
            this.b_usun.TabIndex = 1;
            this.b_usun.Text = "Usun";
            this.b_usun.UseVisualStyleBackColor = true;
            this.b_usun.Click += new System.EventHandler(this.b_usun_Click);
            // 
            // b_dodaj
            // 
            this.b_dodaj.Location = new System.Drawing.Point(12, 308);
            this.b_dodaj.Name = "b_dodaj";
            this.b_dodaj.Size = new System.Drawing.Size(250, 23);
            this.b_dodaj.TabIndex = 2;
            this.b_dodaj.Text = "Dodaj";
            this.b_dodaj.UseVisualStyleBackColor = true;
            this.b_dodaj.Click += new System.EventHandler(this.b_dodaj_Click);
            // 
            // b_wroc
            // 
            this.b_wroc.Location = new System.Drawing.Point(12, 341);
            this.b_wroc.Name = "b_wroc";
            this.b_wroc.Size = new System.Drawing.Size(250, 23);
            this.b_wroc.TabIndex = 3;
            this.b_wroc.Text = "Wróć";
            this.b_wroc.UseVisualStyleBackColor = true;
            this.b_wroc.Click += new System.EventHandler(this.b_wroc_Click);
            // 
            // Lista_uczestnikow
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(274, 374);
            this.Controls.Add(this.b_wroc);
            this.Controls.Add(this.b_dodaj);
            this.Controls.Add(this.b_usun);
            this.Controls.Add(this.t_lista_uczestnikow);
            this.MaximumSize = new System.Drawing.Size(290, 413);
            this.MinimumSize = new System.Drawing.Size(290, 413);
            this.Name = "Lista_uczestnikow";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Zarządzenie spotkaniami";
            ((System.ComponentModel.ISupportInitialize)(this.t_lista_uczestnikow)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView t_lista_uczestnikow;
        private System.Windows.Forms.Button b_usun;
        private System.Windows.Forms.Button b_dodaj;
        private System.Windows.Forms.Button b_wroc;
    }
}