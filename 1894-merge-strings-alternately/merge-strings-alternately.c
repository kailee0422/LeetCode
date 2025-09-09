char* mergeAlternately(char* word1, char* word2) {
	int word1_len = strlen(word1);
	int word2_len = strlen(word2);
	int i1 = 0, i2 = 0, ir = 0;
	int result_len = word1_len + word2_len;
	char* result = (char*)malloc(sizeof(char) * (result_len+1));
	while (i1 < word1_len && i2 < word2_len) {
		result[ir++] = word1[i1++];
		result[ir++] = word2[i2++];
	}
	if (word1_len<word2_len)
	{
		while (ir<result_len) {
			result[ir++] = word2[i2++];
		}
	}
	else
	{
		while (ir < result_len) {
			result[ir++] = word1[i1++];
		}
	}

	result[result_len] = '\0';
	return result;
}
