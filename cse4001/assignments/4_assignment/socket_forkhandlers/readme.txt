
# compilation instructions:

gcc -o server server.c
gcc -o server server2.c
gcc -o client client.c

# Here is a typical command line:

./server 51717 &

./client localhost 51717

