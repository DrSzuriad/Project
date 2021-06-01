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
    public partial class Lista : Form
    {
        public string conString = "Data Source=DRSZURIAD\\SQLEXPRESS;Integrated Security=True;Connect Timeout=30;Encrypt=False;TrustServerCertificate=False;ApplicationIntent=ReadWrite;MultiSubnetFailover=False";
        public SqlConnection connection;
        public Lista(SqlConnection con)
        {
            InitializeComponent();

            if (con == null || con.State != System.Data.ConnectionState.Open)
            {
                con = new SqlConnection(conString);
                con.Open();
            }
            connection = con;

            string query = "SELECT s.Id,s.Nazwa,s.Opis,s.Data_spotkania,ISNULL(Ilość, 0 ) Ilosć FROM  Projekt_xcom.dbo.Spotkania s LEFT JOIN (SELECT u.IdSpotkania, count(IdSpotkania) as Ilość FROM  Projekt_xcom.dbo.Uczestnik as u GROUP BY u.IdSpotkania) u ON s.ID=u.IdSpotkania";
            SqlDataAdapter lista = new SqlDataAdapter(query, connection);
            DataTable tablica = new DataTable();
            lista.Fill(tablica);
            t_tablica.DataSource = tablica;

            DataGridViewColumn id = t_tablica.Columns[0];
            DataGridViewColumn nazwa = t_tablica.Columns[1];
            DataGridViewColumn opis = t_tablica.Columns[2];
            DataGridViewColumn data = t_tablica.Columns[3];
            DataGridViewColumn ilosc = t_tablica.Columns[4];
            id.Width = 30;
            id.ReadOnly = true;
            id.Resizable = DataGridViewTriState.False;
            nazwa.Width = 150;
            nazwa.ReadOnly = true;
            nazwa.Resizable = DataGridViewTriState.False;
            opis.Width = 300;
            opis.ReadOnly = true;
            opis.Resizable = DataGridViewTriState.False;
            data.Width = 108;
            data.ReadOnly = true;
            data.Resizable = DataGridViewTriState.False;
            data.HeaderText = "Data spotkania";
            ilosc.Width = 38;
            ilosc.ReadOnly = true;
            ilosc.Resizable = DataGridViewTriState.False;
            t_tablica.AutoSizeRowsMode = DataGridViewAutoSizeRowsMode.DisplayedCellsExceptHeaders;
        }

        private void b_usun_spotkanie_Click(object sender, EventArgs e)
        {
            int id_rows = t_tablica.CurrentCell.RowIndex;
            int id = Convert.ToInt32(t_tablica.Rows[id_rows].Cells[0].Value);

            string query_u = "DELETE FROM Projekt_xcom.dbo.Uczestnik where Projekt_xcom.dbo.Uczestnik.IdSpotkania=@numer";
            SqlCommand myCommand_u = new SqlCommand(query_u, connection);
            myCommand_u.Parameters.AddWithValue("@numer", id);
            myCommand_u.ExecuteNonQuery();
            string query = "DELETE FROM Projekt_xcom.dbo.Spotkania where Projekt_xcom.dbo.Spotkania.id=@numer";
            SqlCommand myCommand = new SqlCommand(query, connection);
            myCommand.Parameters.AddWithValue("@numer", id);
            myCommand.ExecuteNonQuery();
            t_tablica.Rows.RemoveAt(id_rows);

        }

        private void b_utworz_spotkanie_Click(object sender, EventArgs e)
        {
            this.Hide();
            Utworz form = new Utworz(connection);
            form.ShowDialog();
            this.Close();
        }

        private void b_dodaj_uczestnika_Click(object sender, EventArgs e)
        {
            int id_rows = t_tablica.CurrentCell.RowIndex;
            if (Convert.ToInt32(t_tablica.Rows[id_rows].Cells[4].Value) >= 25)
            {
                MessageBox.Show("Ilość uczetników osiągnęła masymalną wartość równą 25", "Pełne spotkanie",
                MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                
                int id = Convert.ToInt32(t_tablica.Rows[id_rows].Cells[0].Value);
                this.Hide();
                Dodaj form = new Dodaj(connection, id,0);
                form.ShowDialog();
                this.Close();
            }
        }

        private void b_lista_czestnikow_Click(object sender, EventArgs e)
        {
            int id_rows = t_tablica.CurrentCell.RowIndex;
            int id = Convert.ToInt32(t_tablica.Rows[id_rows].Cells[0].Value);
            this.Hide();
            Lista_uczestnikow form = new Lista_uczestnikow(connection, id);
            form.ShowDialog();
            this.Close();
        }
    }
}
