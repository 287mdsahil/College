Public Class Form1

    Dim students(2) As Student
    Dim dcode = New String() {"CSE", "ETCE", "MECH"}
    Dim dname = New String() {"Computer Science", "Electronics", "Mechanical"}

    Private Sub DisplayRefresh()
        ListView1.Items.Clear()
        For i = 0 To UBound(students)
            Dim Item1 As New ListViewItem(students(i).roll)
            Item1.SubItems.Add(students(i).dept)
            Item1.SubItems.Add(students(i).code)
            Item1.SubItems.Add(students(i).name)
            Item1.SubItems.Add(students(i).address)
            Item1.SubItems.Add(students(i).phone)
            ListView1.Items.Add(Item1)
        Next
    End Sub

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        students(0) = New Student(1, dname(0), dcode(0), "Sahil", "Dubrajpur", "12345678")
        students(1) = New Student(2, dname(1), dcode(1), "Boote", "Durgapur", "14464524")
        students(2) = New Student(3, dname(2), dcode(2), "Tommy", "Baruipur", "52454525")

        'Tab1

        TextBox2.Visible = False
        Label2.Visible = False
        TextBox3.Visible = False
        Label3.Visible = False
        TextBox4.Visible = False
        Label4.Visible = False
        TextBox5.Visible = False
        Label5.Visible = False
        TextBox6.Visible = False
        Label6.Visible = False

        'Tab 2
        ListView1.View = View.Details
        ListView1.LabelEdit = False
        ListView1.FullRowSelect = True
        ListView1.GridLines = True
        DisplayRefresh()

        'Tab 3
        ComboBox1.Items.AddRange(dcode)

    End Sub



    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim r As Int32
        r = TextBox1.Text
        For i = 0 To UBound(students)
            If students(i).roll = r Then
                TextBox2.Visible = True
                Label2.Visible = True
                TextBox2.Text = students(i).dept
                TextBox3.Visible = True
                Label3.Visible = True
                TextBox3.Text = students(i).code
                TextBox4.Visible = True
                Label4.Visible = True
                TextBox4.Text = students(i).name
                TextBox5.Visible = True
                Label5.Visible = True
                TextBox5.Text = students(i).address
                TextBox6.Visible = True
                Label6.Visible = True
                TextBox6.Text = students(i).phone
            End If
        Next
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        Dim d As Int32 = ComboBox1.SelectedIndex
        Dim sdcode As String = Me.dcode(d)
        Dim sdname As String = Me.dname(d)
        Dim sname As String = TextBox9.Text
        Dim saddress As String = TextBox8.Text
        Dim sphone As String = TextBox7.Text
        Dim sroll As Int32 = UBound(students) + 1

        students(UBound(students)) = New Student(sroll, sdname, sdcode, sname, saddress, sphone)
        DisplayRefresh()
        MessageBox.Show("added with Roll:")
        TextBox9.Clear()
        TextBox7.Clear()
        TextBox8.Clear()
        ComboBox1.SelectedIndex = -1

    End Sub
End Class
