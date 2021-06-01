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
    public partial class Lista_uczestnikow : Form
    {
        SqlConnection connection;
        int id_spotkania;
        public Lista_uczestnikow(SqlConnection con, int id_spot)
        {
            InitializeComponent();
            connection = con;
            id_spotkania = id_spot;



            string query = "Select Id, Imie, Nazwisko from Projekt_xcom.dbo.Uczestnik where IdSpotkania=@id_spotkania;";
            SqlCommand myCommand = new SqlCommand(query, connection);
            myCommand.Parameters.AddWithValue("@id_spotkania", id_spotkania);
            SqlDataAdapter lista = new SqlDataAdapter(myCommand);
            DataTable tablica = new DataTable();
            lista.Fill(tablica);
            t_lista_uczestnikow.DataSource = tablica;

            DataGridViewColumn id = t_lista_uczestnikow.Columns[0];
            id.Width = 30;
            id.ReadOnly = true;
            id.Resizable = DataGridViewTriState.False;
            DataGridViewColumn imie = t_lista_uczestnikow.Columns[1];
            imie.Width = 100;
            imie.ReadOnly = true;
            imie.Resizable = DataGridViewTriState.False;
            DataGridViewColumn nazwisko = t_lista_uczestnikow.Columns[2];
            nazwisko.Width = 100;
            nazwisko.ReadOnly = true;
            nazwisko.Resizable = DataGridViewTriState.False;

            t_lista_uczestnikow.AutoSizeRowsMode = DataGridViewAutoSizeRowsMode.DisplayedCellsExceptHeaders;
        }

        private void b_usun_Click(object sender, EventArgs e)
        {
            int id_rows = t_lista_uczestnikow.CurrentCell.RowIndex;
            int id = Convert.ToInt32(t_lista_uczestnikow.Rows[id_rows].Cells[0].Value);

            string query_u = "DELETE FROM Projekt_xcom.dbo.Uczestnik where Projekt_xcom.dbo.Uczestnik.Id=@numer";
            SqlCommand myCommand_u = new SqlCommand(query_u, connection);
            myCommand_u.Parameters.AddWithValue("@numer", id);
            myCommand_u.ExecuteNonQuery();
            t_lista_uczestnikow.Rows.RemoveAt(id_rows);
        }

        private void b_dodaj_Click(object sender, EventArgs e)
        {

            if (t_lista_uczestnikow.Rows.Count >= 25)
            {
                MessageBox.Show("Ilość uczetników osiągnęła masymalną wartość równą 25", "Pełne spotkanie",
                MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                this.Hide();
                Dodaj form = new Dodaj(connection, id_spotkania, 1);
                form.ShowDialog();
                this.Close();
            }
        }

        private void b_wroc_Click(object sender, EventArgs e)
        {
            this.Hide();
            Lista form = new Lista(connection);
            form.ShowDialog();
            this.Close();
        }
    }
}
