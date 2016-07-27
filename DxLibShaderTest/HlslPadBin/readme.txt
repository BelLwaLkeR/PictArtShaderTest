HlslPad

2011 �N 11 ��
pmansato
pmansato@kanazawa-net.ne.jp
http://www.kanazawa-net.ne.jp/~pmansato/

�y HlslPad �Ƃ́z
�G�t�F�N�g�t�@�C���i.fx �t�@�C���j�́AHLSL "High Level Shading Language" ���g���č쐬���܂����AHlslPad �� HLSL �̕ҏW���ʂ��e�X�g���邽�߂̃c�[���ł��B

�y�g�����z
���߂� HlslPad ���g���ꍇ�́AHlslPad ���N���������ƁA������ [�R���p�C��] ���Ă��������B�E���̉摜���O���[�X�P�[���ɂȂ�܂��BHlslPad �̋@�\�͂��ꂾ���ł��B

Shader ��K�p����e�X�g�p�̉摜�͂��łɕ\������Ă���͂��ł����A�ق��̂��̂��悯��Ή摜�t�@�C����I�����Ă��������B2 �̉摜�̂����A�����͏�ɃI���W�i���̂܂܂ł��BShader �͉E���̉摜�ɓK�p���܂��B

�t�H�[������̃e�L�X�g�{�b�N�X�� HLSL ���������񂾂��ƁA[�R���p�C��] ���A�R���p�C��������I������ƁA�E���̉摜�� Shader ��K�p���܂��B�R���p�C�����ɃG���[������΁A�t�H�[�������̃e�L�X�g�{�b�N�X�ɃG���[�̓��e��\�����܂��B

���̉摜�ɖ߂��ꍇ�� [���Z�b�g] ���Ă��������B�������A�R���p�C���̂��тɃ��Z�b�g����K�v�͂���܂���B

���j���[�� [PS �t�@�C���Ƃ��ďo�͂���] ��I������ƁA�R���p�C����̓��e�� PS �t�@�C���Ƃ��ăJ�����g�f�B���N�g���ɏo�͂��܂��B�o�̓t�@�C�����͏�� output.ps �ł��B�t�@�C�������w�肷�邱�Ƃ͂ł��܂���B

���j���[�� [�摜�Ƃ��ďo�͂���] ��I������ƁAShader �K�p�O��̉摜�� JPEG �t�@�C���Ƃ��ĕۑ����܂��B�t�@�C������ output.jpg �ł��B

�t�H�[���E���� �mShader Model�n�́AShader �̃o�[�W������I�����܂��B.NET Framework 4.0 �ł� PS2.0 �� PS3.0 �̈ꕔ���L���ł��B

�Ȃ��AHlslPad ���I�����̈ʒu�ƃT�C�Y���������t�@�C���ɋL�^���A���̋N�����Ɉʒu�ƃT�C�Y���Č����܂��B�܂��A�t�H�[���̃T�C�Y��ύX����ƁA�摜������ɑΉ�����T�C�Y�ɕύX�ł��܂��B

�yHLSL �̊�{�z
HLSL �� C ���̍\�����g���܂����AC/C++ �� C# �Ƃ͖��炩�ɈقȂ�܂��B�ǂ��炩�Ƃ����ƁA�A�Z���u������̃`���b�g�����łƂ��������ł��BHLSL �̉���͕ʂ̋@����l���Ă��܂��̂ŁA�����ł͊�{�I�Ȃ��Ƃ����������܂��B

1. �啶���Ə������̋�ʂ͂Ȃ�
  �L�[���[�h����ѕϐ��Ȃǂ̎��ʖ��ɑ΂��āA�啶���Ə������̋�ʂ͂���܂���BC/C++ �œ`���I�Ȃ��ׂď��������g�����@�ł������ł����AC# �I�ɂ̓J�������A�܂�A���[�h�̐擪�̕���������啶���ɂ��邱�Ƃ������߂܂��B�܂��A�Ӗ��̂���L�[���[�h�����ׂđ啶���ɂ���͎̂��F���������Ȃ���ʂ�����܂��B

�ȉ��̃R�[�h�́A���̃z�[���y�[�W�Ō��J���Ă�����̂ł����A�J�������̕ϐ��� blankColor ��L�[���[�h�� TEXCOORD �Ȃǂ��Q�l�ɂ��Ă��������B

	float threshold : register(c0);

	sampler2D input : register(s0);
	float4 blankColor : register(c1);

	float4 main(float2 uv : TEXCOORD) : COLOR
	{
	  float4 color = tex2D(input, uv);
	  float intensity = (color.r + color.g + color.b) / 3;

	  float4 result;

	  if (intensity > threshold)
	  {
	    result = color;
	  }
	  else
	  {
	    result = blankColor;
	  }

	  return result;
	}

2. �����R�[�h
  �G�t�F�N�g�t�@�C���i.fx �t�@�C���j�̕����R�[�h�́AASCII �łȂ���΂Ȃ�܂���Bshift-jis �͉p�����ƋL���Ɍ����Ă� ASCII �Ɠ����Ȃ̂ŁA�g���܂��B�������A���{��i�����Ȃǁj���܂ނƃR���p�C���G���[�ɂȂ�܂��B

3. �O���[�o���ϐ��ƃ��[�J���ϐ�
  ��L�̃R�[�h�� threshold�Ainput�AblankColor �̓O���[�o���ϐ��ŁA�錾���ɏ����l��^���邱�Ƃ͂ł��܂���B�l�̐ݒ�̓��W�X�^�𒼐ڐݒ肵�Ȃ���΂Ȃ�܂���B����Acolor �� intensity �̓��[�J���ϐ��ł��B

4. �O���[�o���ϐ��̕ύX
  HlslPad �͔ėp�� ShaderEffect �I�u�W�F�N�g���g���܂��B�������邱�ƂŁA�G�t�F�N�g�t�@�C���ɑΉ����� ShaderEffect �N���X����h������N���X���`�����Ԃ��ȗ����Ă��܂��B����ɂ� Input �v���p�e�B�ƒ萔���W�X�^�� C0 �� C1 �ɑΉ�����v���p�e�B������ݒ肵�Ă��܂��B

  �O���[�o���ϐ��̓��W�X�^�𒼐ڑ��삷�邱�ƂŕύX�\�ł��BHlslPad �ł� C0 �� C1 ���W�X�^���������s���ɕύX�\�ɂ��܂����B�t�H�[���E���� 2 �̃X���C�_�R���g���[���͂��ꂼ�� C0 �� C1 �ƂɑΉ����Ă��܂��B�l�� 0.0 �` 1.0 �͈̔͂̐��l�ł��B�����A100 �Ƃ��̑傫�Ȓl���K�v�ȏꍇ�̓��[�J���ϐ����g���Ή����ł��܂��B���Ƃ��΁A�O���[�o���ϐ� someValue �����̂悤�ɐ錾���Ă���Ƃ��܂��B

  float someValue : register(C0);

main �֐����őΉ����郍�[�J���ϐ���錾���A100 ����Z���܂��B

  float localValue = someValue * 100;

������O���[�o���ϐ��̑���Ɏg���΁A�X���C�_�R���g���[���ŃO���[�o���ϐ������s���ɕύX�\�ɂł��܂��B

��ɐ��������Ƃ���AHlslPad �ł� C0 �� C1 �݂̂�ύX�\�ɂ��Ă��܂��BC2 ���g�������Ƃ��Afloat4 �^�̃J���[�l�𒼐ڐݒ肵�����ꍇ�ɂ͑Ή����Ă��܂���B�������A�ꎞ�I�Ƀ��[�J���ϐ��Ƃ��Đݒ肷��΃e�X�g���邱�Ƃ͉\�ł��B�l�̐ݒ�͎���͂ɂȂ�܂����A���̕��@�͂ǂ������P�[�X�ɂ��K�p�\�ł��B���Ƃ��΁A�{���̓O���[�o���ϐ��Ƃ��� backColor �� COLOR �^�� C2 �ɓo�^�������ꍇ�A�ȉ��̂悤�ɂ���΃e�X�g�ł��܂��B

  float4 backColor : register(C2); �� �{������������

�O���[�o���ϐ��� // �ŃR�����g�A�E�g���A���炽�߂� ���[�J���ϐ��Ƃ��Đ錾���܂��B�l�͎���͂Őݒ肵�Ă��������B

	float4 main(float2 uv : TEXCOORD) : COLOR
	{
		float4 backColor = { 0.4, 0.6, 0.8, 1.0 };
		....
	}

5. ���C���֐���
  HlslPad �ł̓��C���֐����Ƃ��āAmain �������L���ł��B

6. ���W�l
  ��L�̃R�[�h�� uv �� TEXCOORD �^���󂯎��܂����A����� (0.0, 0.0) �` (1.0, 1.0) �͈̔͂̐��l�ŁA����Ώۂ� UIElement �I�u�W�F�N�g�̍���������_�Ƃ�����W�l�ł��B

7. Shader �̃o�[�W����
  HlslPad �ł� 2.0 �� 3.0 ���w��ł���悤�ɂ��܂����B.NET Framework 4.0 �ł� 3.0 �������t���Ŏg�p�\�ł����A�ʏ�� 2.0 �ɂ��邱�Ƃ������߂܂��B�������A2.0 �Ő���ɃR���p�C���ł��Ȃ��ꍇ�� 3.0 �������Ă��������BWEB �T�C�g�ȂǂŌ��J����Ă���T���v���R�[�h�̒��ɂ� 3.0 �łȂ���΂Ȃ�Ȃ��ꍇ������܂��̂ŁB

�y���쌠�z
HlslPad.exe �̓t���[�E�G�A�ł��B�ǂȂ��ł����R�ɂ��g�����������B

HlslPad �̃\�[�X�R�[�h�͎������J���Ă��� NETClass �܂��� WPFClass �̃��[�U�[����Ɍ��J���܂��BZIP �t�@�C�����𓀂��邽�߂̃p�X���[�h�� NETClass �Ɠ����ɂȂ��Ă��܂��B�Ȃ��A�v���W�F�N�g�� Visual Studio 2010  C# �ō��܂����B

�|�ȏ�|
