using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.Remoting;
using System.Runtime.Remoting.Channels.Tcp;
using System.Runtime.Remoting.Channels;

    class Program
    {
        static void Main(string[] args)
        {
            TcpClientChannel channel = new TcpClientChannel();
            ChannelServices.RegisterChannel(channel, false);

            string playerURL = "tcp://localhost:" + 23456 + "/" + "Player";
            RPCDemo.Player player = (RPCDemo.Player)Activator.GetObject(typeof(RPCDemo.Player), playerURL);

            while (true)
            {
                Console.Write("Type a message to the server or type 'quit' to exit\n");
                string text = Console.ReadLine();

                if (text == "quit")
                {
                    break;
                }

                player.SayHello(text);
            }
        }
    }

