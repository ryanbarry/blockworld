#version 150

// Input vertex data, different for all executions of this shader.
in vec2 vertexPosition_screenspace;
in vec2 vertexUV;

// Output data ; will be interpolated for each fragment.
out vec2 UV;

void main(){

	// Output position of the vertex, in clip space
	// map [0..1024][0..768] to [-1..1][-1..1]
	// first [0..1024][0..768] -> [-512..512][-384..384]
	vec2 vertexPosition_homogeneousspace = vertexPosition_screenspace - vec2(512,384);
	// then [-512..512][-384..384] -> [-1..1][-1..1]
	vertexPosition_homogeneousspace /= vec2(512,384);
	gl_Position =  vec4(vertexPosition_homogeneousspace,0,1);
	
	// UV of the vertex. No special space for this one.
	UV = vertexUV;
}