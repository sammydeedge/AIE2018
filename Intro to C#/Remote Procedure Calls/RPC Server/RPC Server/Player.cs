using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RPCDemo
{
    class Player : MarshalByRefObject
    {
        public void SayHello(string text)
        {
            Console.WriteLine("The client says:" + text);
        }
    }

}
