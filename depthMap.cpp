#include "stdafx.h"
#include "depthMap.h"
DepthMap::DepthMap(int width, int height) {
	shadowWidth = width;
	shadowHeight = height;

	glGenFramebuffers(1, &depthMapFBO);
	glGenTextures(1, &depthMap);
	glBindTexture(GL_TEXTURE_2D, depthMap);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, shadowWidth, shadowHeight, 0, GL_DEPTH_COMPONENT, GL_FLOAT, nullptr);//�ռ����ڱ������ֵ�������ϴ�����
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);	//��������Ϊ��Եɫ��1����������
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	GLfloat borderColor[] = { 1.0, 1.0, 1.0, 1.0 };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);

	glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);	//��֡��������
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMap, 0);	//֡���������������������Ⱦ������ռ�
	glDrawBuffer(GL_NONE);	//֡������������ɫ���塢��Ȼ����
	glReadBuffer(GL_NONE);	//��ʽ˵��������ɫ���ݣ�д����ɫ����������ȡ��ɫ������
	glBindFramebuffer(GL_FRAMEBUFFER, 0);	//ע����
}
