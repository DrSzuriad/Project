using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace Spotkaniav2
{
    public partial class Utworz : Form
    {
        public SqlConnection connection;
        public Utworz(SqlConnection con)
        {
            InitializeComponent();
            connection = con;
        }

        private void b_dodaj_Click(object sender, EventArgs e)
        {

            if (t_nazwa.Text == "") 
            {
                MessageBox.Show("Nazwa spotkania nie może być pusta", "Brak nazwy",
                MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if (t_opis.Text == "") 
            {
                MessageBox.Show("Opis spotkania nie może być pusty", "Brak opisu", 
                MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {

                string data = k_data_spotkania.SelectionStart.Year.ToString() + "-" + k_data_spotkania.SelectionStart.Month.ToString() + "-" + k_data_spotkania.SelectionStart.Day.ToString();
                data += " " + k_godzina_spotkania.Text;
                string query = "INSERT INTO Projekt_xcom.dbo.Spotkania VALUES (@Nazwa, @Opis, @Data_spotkania)";

                SqlCommand myCommand = new SqlCommand(query, connection);
                myCommand.Parameters.AddWithValue("@Nazwa", t_nazwa.Text);
                myCommand.Parameters.AddWithValue("@Opis", t_opis.Text);
                myCommand.Parameters.AddWithValue("@Data_spotkania", data);
                myCommand.ExecuteNonQuery();

                this.Hide();
                Lista form = new Lista(connection);
                form.ShowDialog();
                this.Close();
            }

        }

        private void b_anuluj_Click(object sender, EventArgs e)
        {
            this.Hide();
            Lista form = new Lista(connection);
            form.ShowDialog();
            this.Close();
        }


    }
}
