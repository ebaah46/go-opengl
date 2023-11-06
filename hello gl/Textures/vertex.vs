//
//  vertex.vs
//  Textures
//
//  Created by Emmanuel Baah on 20.9.2023.
//

#version core 3.3
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 ourColor;
out vec2 texCoord;
int main(){
    gl_Position = vec4(aPos, 1,0);
    ourColor = aColor;
    texCoord = aTexCoord;
}
