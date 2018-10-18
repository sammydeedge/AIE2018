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
        //Creating server
        TcpServerChannel channel = new TcpServerChannel(23456);
        ChannelServices.RegisterChannel(channel, false);

        //Register Player
        RemotingConfiguration.RegisterWellKnownServiceType(typeof(RPCDemo.Player), "Player", WellKnownObjectMode.SingleCall);

        Console.WriteLine("Listening for requests.\nPress enter to exit...\n");
        Console.ReadLine();
    }
}
