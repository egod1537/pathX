using UnityEditor;
using UnityEngine;

namespace PathX
{
    [CustomEditor(typeof(ViewProbeJSON))]
    public class EditorViewProbeJSON : Editor
    {
        ViewProbeJSON script;
        string json;

        private void OnEnable()
        {
            script = (ViewProbeJSON)target;
        }

        public override void OnInspectorGUI()
        {
            base.OnInspectorGUI();

            if (GUILayout.Button("Extract JSON"))
            {
                json = script.ExtractJSON();
            }

            EditorGUILayout.TextArea(json, GUILayout.Height(100));
        }
    }
}