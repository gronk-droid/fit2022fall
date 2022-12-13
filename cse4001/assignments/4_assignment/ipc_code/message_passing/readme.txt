Passing messages between processes

compilation: 

      gcc message_send.c -o message_send
      gcc message_rec.c -o message_rec


running: 

      ./message_send
      ./message_rec



Open two terminals: 

On Terminal 1, run ./message_rec on one terminal. It will wait until the message is sent by ./message_send runs. 

One Terminal 2, run ./message_send. Program ./message_rec will output the sent message.



