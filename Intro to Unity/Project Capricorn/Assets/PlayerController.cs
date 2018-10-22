using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour {

    [Range (15,45)]
    public float speed = 10.0f;
    public float turnSpeed = Mathf.PI;

    public GameObject BulletPrefab;

    private Transform fireLocation;

    Rigidbody m_rigidbody;

	// Use this for initialization
	void Start () {
        fireLocation = transform.Find("FirePoint");
        m_rigidbody = GetComponent<Rigidbody>();
        m_rigidbody.constraints = RigidbodyConstraints.FreezePositionZ | RigidbodyConstraints.FreezeRotationX | RigidbodyConstraints.FreezeRotationZ;
        Debug.Assert(fireLocation);
	}
	
	// Update is called once per frame
	void Update () {
        if (Input.GetKey(KeyCode.UpArrow))
        { transform.Translate(transform.forward * speed * Time.deltaTime); }

        if (Input.GetKey(KeyCode.DownArrow))
        { transform.Translate(-transform.forward * speed * Time.deltaTime); }

        if (Input.GetKey(KeyCode.LeftArrow))
        { Quaternion rot = Quaternion.AngleAxis(-turnSpeed * Time.deltaTime, Vector3.up);
            transform.rotation *= rot;
                }

        if (Input.GetKey(KeyCode.RightArrow))
        { Quaternion rot = Quaternion.AngleAxis(turnSpeed * Time.deltaTime, Vector3.up);
           transform.rotation *= rot;
        }

        if (Input.GetKeyDown(KeyCode.Space))
        {
            Transform firelocation = transform.Find("FirePoint");
            Debug.Assert(firelocation);

            GameObject newObject = Instantiate(BulletPrefab, transform.position, transform.rotation);
        }
    }
}
