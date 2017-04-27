using UnityEngine;
using System.Collections;

public class MoveCamera : MonoBehaviour {

    public bool play = true;

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
        if (play == true)
        {
            if (gameObject.transform.position.x >= -10 && gameObject.transform.position.x <= 10)
            {
                transform.Translate(Input.acceleration.x, 0, 0);
            }
            if (gameObject.transform.position.x < -10)
            {
                gameObject.transform.position = new Vector3(-10, gameObject.transform.position.y, gameObject.transform.position.z);
            }
            else if (gameObject.transform.position.x > 10)
            {
                gameObject.transform.position = new Vector3(10, gameObject.transform.position.y, gameObject.transform.position.z);
            }
            if (Input.GetKey(KeyCode.LeftArrow) == true && GameObject.Find("GvrMain").transform.position.x >= -10 && GameObject.Find("GvrMain").transform.position.x <= 10)
            {
                transform.Translate(-1, 0, 0);
            }
            if (Input.GetKey(KeyCode.RightArrow) == true && GameObject.Find("GvrMain").transform.position.x >= -10 && GameObject.Find("GvrMain").transform.position.x <= 10)
            {
                transform.Translate(1, 0, 0);
            }
            if (gameObject.name == "CameraCube")
            {
                if (gameObject.transform.position.z != -9)
                {
                    play = false;
                    GameObject camera = GameObject.Find("GvrMain");
                    MoveCamera cameraScript = camera.GetComponent<MoveCamera>();
                    cameraScript.play = false;
                }
            }
        }
        if (play == false)
        {
            if (Input.GetMouseButtonDown(0))
            {
                //Touch anywhere
                play = true;
                GameObject camera = GameObject.Find("GvrMain");
                MoveCamera cameraScript = camera.GetComponent<MoveCamera>();
                cameraScript.play = true;
                if (gameObject.name == "CameraCube")
                {
                    gameObject.transform.position = (new Vector3 (gameObject.transform.position.x, gameObject.transform.position.y, -9));
                    Rigidbody objectRB = gameObject.GetComponent<Rigidbody>();
                    objectRB.velocity = new Vector3(0, 0, 0);
                }
            }
        }
	}
}
