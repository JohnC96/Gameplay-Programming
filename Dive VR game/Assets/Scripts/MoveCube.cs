using UnityEngine;
using System.Collections;

public class MoveCube : MonoBehaviour {

    bool play = true;

	// Use this for initialization
	void Start () {
        var number = Random.Range(-10, 11);
        gameObject.transform.position = new Vector3(number, 0.5f, gameObject.transform.position.z);
    }
	
	// Update is called once per frame
	void Update () {
        if (play == true)
        {
            transform.Translate(0, 0, -0.5f);
            if (gameObject.transform.position.z < -15)
            {
                var number = Random.Range(-10, 11);
                gameObject.transform.position = new Vector3(number, 0.5f, 30);
            }
        }
	}

    private void OnCollisionEnter(Collision other)
    {
        if (other.gameObject.tag == "GvrMain" || other.gameObject.tag == "CameraCube")
        {
            print("Trigger");
            Destroy(gameObject);
            play = false;
            GameObject camera = GameObject.Find("GvrMain");
            MoveCamera cameraScript = camera.GetComponent<MoveCamera>();
            cameraScript.play = false;
        }
    }
}
