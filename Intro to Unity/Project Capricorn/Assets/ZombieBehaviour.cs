using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(Rigidbody))]
public class ZombieBehaviour : MonoBehaviour {

    private GameObject target;

    public ForceMode TypeOfForce;
    private Vector3 targetlocation;
    int timer = 0;

    [Range(10,100)]
    public int forceUpdate;

    public bool runZombie;
    // Use this for initialization
    void Start () {
        target = GameObject.Find("the_player");
    }
	
	// Update is called once per frame
	void Update () {
        if (runZombie)
        {
             if (timer < forceUpdate) { timer++; }
                    else
                    {
                         targetlocation = target.transform.position;
                         Vector3 mylocation = transform.position;

                         GetComponent<Rigidbody>().AddForce((targetlocation - mylocation), TypeOfForce);
                        timer = 0;
                    }
        }
    }
}
