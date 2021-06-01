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
    public partial class Dodaj : Form
    {

        public SqlConnection connection;
        int id_spotkania;
        int powrot;
        public Dodaj(SqlConnection con, int id_spotk, int pow)
        {
            InitializeComponent();
            connection = con;
            id_spotkania = id_spotk;
            powrot = pow;
        }

        void zamkniecie()
        {
            this.Hide();
            if (powrot == 1)
            {
                Lista_uczestnikow form = new Lista_uczestnikow(connection, id_spotkania);
                form.ShowDialog();

            }
            else
            {
                Lista form = new Lista(connection);
                form.ShowDialog();
            }
            this.Close();
        }

        private void b_anuluj_Click(object sender, EventArgs e)
        {
            zamkniecie();
        }

        private void b_dodaj_Click(object sender, EventArgs e)
        {

            if (t_imie.Text == "")
            {
                MessageBox.Show("Nie podano imienia", "Imię uczestnika spotakania nie może być puste.",
                MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if (t_nazwisko.Text == "")
            {
                MessageBox.Show("Nie podano nazwiska", "Nazwisko uczestnika spotakania nie może być puste.",
                MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {

                string query = "INSERT INTO Projekt_xcom.dbo.Uczestnik VALUES (@imie, @nazwisko, @id_spotkania)";

                SqlCommand myCommand = new SqlCommand(query, connection);
                myCommand.Parameters.AddWithValue("@imie", t_imie.Text);
                myCommand.Parameters.AddWithValue("@nazwisko", t_nazwisko.Text);
                myCommand.Parameters.AddWithValue("@id_spotkania", id_spotkania);
                myCommand.ExecuteNonQuery();

                zamkniecie();
            }
        }
    }
}
