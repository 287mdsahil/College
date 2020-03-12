st -o logs/p_0.8_Server.log -e java Server &
sleep 1
st -o logs/p_0.8_Client1.log -e java Client 00000000 p &
st -o logs/p_0.8_Client2.log -e java Client 11111111 p &
st -o logs/p_0.8_Client3.log -e java Client 11110000 p 
