Public Class Form2

    Dim s As Student

    Private Sub Form2_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        ComboBox1.Items.AddRange(Form1.dcode)
    End Sub

    Private Sub Form2_FormClosing(sender As Object, e As EventArgs) Handles MyBase.FormClosing
        Form1.Show()
    End Sub



    Public Sub sendStudent(ByRef ss As Student)
        ComboBox1.Text = ss.code
        TextBox9.Text = ss.name
        TextBox8.Text = ss.address
        TextBox7.Text = ss.phone

        For x = 1 To UBound(Form1.dcode)
            If ss.code = Form1.dcode(x) Then
                ComboBox1.SelectedIndex = x
                Exit For
            End If
        Next
        s = ss
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click

        Dim result As DialogResult = MessageBox.Show("Are You sure", "Confirmation", MessageBoxButtons.OKCancel)
        If result = DialogResult.OK Then
            s.code = ComboBox1.Text
            s.dept = Form1.dname(ComboBox1.SelectedIndex)
            s.name = TextBox9.Text
            s.address = TextBox8.Text
            s.phone = TextBox7.Text
            Form1.DisplayRefresh()
            MessageBox.Show("Student corresponding to roll:" + s.roll.ToString() + " edited")
        Else
            MessageBox.Show("Operation aborted by user!")
            Form1.Show()
            Form1.DisplayRefresh()
        End If
        Close()
    End Sub
End Class