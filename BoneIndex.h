Vector3 GetBoneWithRotation(DWORD_PTR mesh, int id)
{
	uintptr_t bone_array = read<uintptr_t>(mesh + OFFSETS::BoneArray);
	int is_bone_array_cached = read<int>(mesh + 0x5f0);
	if (is_bone_array_cached) bone_array = read<uintptr_t>(mesh + 0x5f0);
	FTransform bone = read<FTransform>(bone_array + (id * 0x60));
	FTransform component_to_world = read<FTransform>(mesh + OFFSETS::ComponetToWorld);
	D3DMATRIX matrix = MatrixMultiplication(bone.ToMatrixWithScale(), component_to_world.ToMatrixWithScale());
	return Vector3(matrix._41, matrix._42, matrix._43);
}