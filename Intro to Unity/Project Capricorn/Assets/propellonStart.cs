using System.Collections;
using System.Collections.Generic;
using UnityEngine;


[RequireComponent(typeof(Rigidbody))]
public class propellonStart : MonoBehaviour {

    public float ForceAmount = 10.0f;
    public ForceMode TypeOfForce = ForceMode.VelocityChange;

    private float timer;
    public float lifespan;
    

	// Use this for initialization
	void Start () {
        GetComponent<Rigidbody>().AddForce(transform.forward * ForceAmount, TypeOfForce);
	}
	
	// Update is called once per frame
	void Update () {
        timer += (float)Time.deltaTime;

        if (timer >= lifespan) { Destroy(this); }
        
	}
}
