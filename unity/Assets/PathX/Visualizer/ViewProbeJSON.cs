using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using UnityEngine;

namespace PathX
{
    [ExecuteAlways]
    public class ViewProbeJSON : MonoBehaviour
    {
        public float scale = 1.0f;
        public Vector2 world;
        public float viewDistance;

        private ViewProjectionCamera _projectionCamera;
        public ViewProjectionCamera projectionCamera { get => GetProjectionCamera(); }

        void OnEnable()
        {
            GetProjectionCamera();
        }

        public string ExtractJSON()
        {
            ViewJSON viewJSON = new ViewJSON();
            viewJSON.world = ExtractWorld();
            viewJSON.gameObjects = ExtractGameObjects();
            return JsonUtility.ToJson(viewJSON, true);
        }

        private Vector2 ExtractWorld()
        {
            return world;
        }

        // TODO: 삼각분할 -> 투영 -> dll boolean operation -> 마샬링
        private List<ViewGameObject> ExtractGameObjects()
        {
            List<ViewGameObject> gameObjects = new();

            Transform root = transform.Find("GameObjects");
            if (root == null)
            {
                Debug.LogError("GameObjects is not exist in child");
                return gameObjects;
            }

            ViewPlane viewPlane = projectionCamera.viewPlane;
            int childCount = root.childCount;
            for (int i = 0; i < childCount; i++)
            {
                Transform child = root.GetChild(i);
                MeshFilter meshFilter = child.GetComponent<MeshFilter>();
                if (meshFilter == null) continue;
                Mesh mesh = meshFilter.sharedMesh;

                List<Vector2> vertices = new(mesh.vertices.Length);
                foreach (var vertex in mesh.vertices)
                {
                    Vector3 worldPoint = transform.TransformPoint(vertex);
                    Vector2 projected = viewPlane.Project2DPoint(worldPoint);
                    vertices.Add(projected);
                }

                ViewGameObject viewGameObject = new(child.name, vertices);
                gameObjects.Add(viewGameObject);
            }

            return gameObjects;
        }

        private ViewProjectionCamera GetProjectionCamera()
        {
            if (_projectionCamera == null)
            {
                GameObject go = new GameObject("Projection Camera");
                Transform tr = go.transform;
                tr.SetParent(transform);
                tr.SetSiblingIndex(0);

                _projectionCamera = go.AddComponent<ViewProjectionCamera>();
            }
            return _projectionCamera;
        }

        public void OnGizmosSelected()
        {

        }
    }

}