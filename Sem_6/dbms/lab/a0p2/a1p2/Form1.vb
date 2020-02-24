Public Class Form1

    Dim students As New List(Of Student)()
    Public dcode = New String() {"CSE", "ETCE", "MECH"}
    Public dname = New String() {"Computer Science", "Electronics", "Mechanical"}
    Dim s As Student
    Dim displayStart As Int32

    Private Function min(ByVal a As Int32, ByVal b As Int32)
        If (a > b) Then
            Return b
        Else
            Return a
        End If
    End Function

    Public Sub DisplayRefresh()
        DataGridView1.Rows.Clear()
        For i = displayStart To min(students.Count - 1, displayStart + 5 - 1)
            Me.DataGridView1.Rows.Add(students(i).roll, students(i).code, students(i).name, students(i).address, students(i).dept, students(i).phone)
        Next
    End Sub

    Private Sub DisplayButtons()
        If (displayStart < 5) Then
            Button6.Visible = False
        Else
            Button6.Visible = True
        End If


        If (displayStart + 5 > students.Count - 1) Then
            Button7.Visible = False
        Else
            Button7.Visible = True
        End If
    End Sub

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        students.Add(New Student(1, dname(0), dcode(0), "Sahil", "Dubrajpur", "12345678"))
        students.Add(New Student(2, dname(1), dcode(1), "Boote", "Durgapur", "14464524"))
        students.Add(New Student(3, dname(2), dcode(2), "Tommy", "Baruipur", "52454525"))
        students.Add(New Student(4, dname(2), dcode(2), "Irin", "Jadavpur", "52454525"))
        students.Add(New Student(5, dname(2), dcode(2), "Sadrul", "Burdwan", "52454525"))
        students.Add(New Student(6, dname(2), dcode(2), "Anindya", "Durgapur", "52454525"))
        students.Add(New Student(7, dname(2), dcode(2), "Ani", "Durgapur", "52454525"))
        students.Add(New Student(8, dname(2), dcode(2), "Irin", "Jadavpur", "52454525"))
        students.Add(New Student(9, dname(2), dcode(2), "Sadrul", "Burdwan", "52454525"))
        students.Add(New Student(10, dname(2), dcode(2), "Anindya", "Durgapur", "52454525"))
        students.Add(New Student(11, dname(2), dcode(2), "Ani", "Durgapur", "52454525"))
        displayStart = 0
        DisplayButtons()

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
        DisplayRefresh()

        'Tab 3
        ComboBox1.Items.AddRange(dcode)

        'Tab 5
        TextBox14.Visible = False
        Label15.Visible = False
        TextBox13.Visible = False
        Label14.Visible = False
        TextBox12.Visible = False
        Label13.Visible = False
        TextBox11.Visible = False
        Label12.Visible = False
        TextBox10.Visible = False
        Label10.Visible = False
        Button4.Visible = False
        Button5.Visible = False

    End Sub

    Public Function searchByRoll(ByVal r As Int32)
        For i = 0 To students.Count - 1
            If students(i).roll = r Then
                Return students(i)
            End If
        Next
        Return Nothing
    End Function

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim r As Int32
        If String.IsNullOrEmpty(TextBox1.Text) Then
            MessageBox.Show("Please insert a value to search")
            Exit Sub
        End If
        r = TextBox1.Text

        s = searchByRoll(r)
        If s Is Nothing Then
            MessageBox.Show("Not found")
        Else
            TextBox2.Visible = True
            Label2.Visible = True
            TextBox2.Text = s.dept
            TextBox3.Visible = True
            Label3.Visible = True
            TextBox3.Text = s.code
            TextBox4.Visible = True
            Label4.Visible = True
            TextBox4.Text = s.name
            TextBox5.Visible = True
            Label5.Visible = True
            TextBox5.Text = s.address
            TextBox6.Visible = True
            Label6.Visible = True
            TextBox6.Text = s.phone
        End If
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        Dim d As Int32 = ComboBox1.SelectedIndex
        Dim sdcode As String = Me.dcode(d)
        Dim sdname As String = Me.dname(d)
        Dim sname As String = TextBox9.Text
        Dim saddress As String = TextBox8.Text
        Dim sphone As String = TextBox7.Text
        Dim sroll As Int32 = students.Count + 1

        Dim max As Int32 = -1
        For i = 0 To students.Count - 1
            If (students(i).roll > max) Then
                max = students(i).roll
            End If
        Next
        sroll = max + 1


        Dim messageString As String = "Add the student with roll:" & sroll.ToString() & "?"
        Dim resutl As DialogResult = MessageBox.Show(messageString, "Confirmation", MessageBoxButtons.OKCancel)
        If resutl = DialogResult.OK Then
            students.Add(New Student(sroll, sdname, sdcode, sname, saddress, sphone))
            DisplayRefresh()
            MessageBox.Show("New Student added")
        Else
            MessageBox.Show("Operation cancelled by user")
        End If
        TextBox9.Clear()
        TextBox7.Clear()
        TextBox8.Clear()
        ComboBox1.SelectedIndex = -1

    End Sub

    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        Dim r As Int32
        If String.IsNullOrEmpty(TextBox15.Text) Then
            MessageBox.Show("Please insert a value to search")
            Exit Sub
        End If
        r = TextBox15.Text

        s = searchByRoll(r)
        If s Is Nothing Then
            MessageBox.Show("Not found")
        Else
            TextBox14.Visible = True
            Label15.Visible = True
            TextBox14.Text = s.dept
            TextBox13.Visible = True
            Label14.Visible = True
            TextBox13.Text = s.code
            TextBox12.Visible = True
            Label13.Visible = True
            TextBox12.Text = s.name
            TextBox11.Visible = True
            Label12.Visible = True
            TextBox11.Text = s.address
            TextBox10.Visible = True
            Label10.Visible = True
            TextBox10.Text = s.phone
            Button4.Visible = True
            Button5.Visible = True
        End If
    End Sub

    Private Sub Button4_Click(sender As Object, e As EventArgs) Handles Button4.Click
        'Delete entry
        Dim r As Int32
        If String.IsNullOrEmpty(TextBox15.Text) Then
            MessageBox.Show("Please insert a value to search")
            Exit Sub
        End If

        Dim result As DialogResult = MessageBox.Show("Are You sure", "Confirmation", MessageBoxButtons.OKCancel)

        If result = DialogResult.OK Then
            students.Remove(s)
            MessageBox.Show("Student corresponding to roll:" + s.roll.ToString() + " deleted!")
            DisplayRefresh()
        Else
            MessageBox.Show("Operation aborted by user!")
        End If

        TextBox15.Clear()
        TextBox14.Clear()
        TextBox13.Clear()
        TextBox12.Clear()
        TextBox11.Clear()
        TextBox10.Clear()
        TextBox14.Visible = False
        Label15.Visible = False
        TextBox13.Visible = False
        Label14.Visible = False
        TextBox12.Visible = False
        Label13.Visible = False
        TextBox11.Visible = False
        Label12.Visible = False
        TextBox10.Visible = False
        Label10.Visible = False
        Button4.Visible = False
        Button5.Visible = False

    End Sub

    Private Sub Button5_Click(sender As Object, e As EventArgs) Handles Button5.Click
        Form2.Show()
        Form2.sendStudent(s)
        Me.Hide()
        TextBox15.Clear()
        TextBox14.Clear()
        TextBox13.Clear()
        TextBox12.Clear()
        TextBox11.Clear()
        TextBox10.Clear()
        TextBox14.Visible = False
        Label15.Visible = False
        TextBox13.Visible = False
        Label14.Visible = False
        TextBox12.Visible = False
        Label13.Visible = False
        TextBox11.Visible = False
        Label12.Visible = False
        TextBox10.Visible = False
        Label10.Visible = False
        Button4.Visible = False
        Button5.Visible = False
    End Sub

    Private Sub Button6_Click(sender As Object, e As EventArgs) Handles Button6.Click
        displayStart -= 5
        DisplayButtons()
        DisplayRefresh()
    End Sub

    Private Sub Button7_Click(sender As Object, e As EventArgs) Handles Button7.Click
        displayStart = displayStart + 5
        DisplayButtons()
        DisplayRefresh()
    End Sub
End Class
