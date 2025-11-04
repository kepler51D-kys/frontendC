#version 450

layout(location = 0) in vec2 inPosition;

layout(push_constant) uniform PushConstants {
    vec4 rect;
    vec4 color;
} push;

layout(location = 0) out vec4 fragColor;
layout(location = 1) out vec4 rectLocation;

void main() {
    vec4 rect;
    vec2 screenPos = push.rect.xy + (inPosition * push.rect.zw);
    
    gl_Position = vec4(screenPos * 2.0 - 1.0, 0.0, 1.0);
    
    gl_Position.y = -gl_Position.y;
    
    fragColor = push.color;
}