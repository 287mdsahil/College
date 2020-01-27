Public Class Form1

    Dim num1 As Double
    Dim num2 As Double
    Dim num3 As Double
    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim s As String
        s = TextBox1.Text
        If s = String.Empty Then
            num1 = 0
        Else
            num1 = Double.Parse(s)
        End If
        s = TextBox2.Text
        If s = String.Empty Then
            num2 = 0
        Else
            num2 = Double.Parse(s)
        End If

        num3 = (num1 + num2)
        Label1.Text = CStr(num3)
    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        Dim s As String
        s = TextBox1.Text
        If s = String.Empty Then
            num1 = 0
        Else
            num1 = Double.Parse(s)
        End If
        s = TextBox2.Text
        If s = String.Empty Then
            num2 = 0
        Else
            num2 = Double.Parse(s)
        End If
        num3 = (num1 - num2)
        Label1.Text = CStr(num3)
    End Sub

    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick
        Text = "Add and Sub " + Date.Now.ToString()
    End Sub
End Class
