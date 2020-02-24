Public Class Student
    'roll,dept,code,name,address,phone
    Public roll As Int32
    Public dept As String
    Public code As String
    Public name As String
    Public address As String
    Public phone As String

    Public Sub New(ByVal r As String, ByVal d As String, ByVal c As String, ByVal n As String, ByVal a As String, ByVal p As String)
        roll = r
        dept = d
        code = c
        name = n
        address = a
        phone = p
    End Sub
End Class
