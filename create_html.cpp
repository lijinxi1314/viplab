<html>
<table>
<tr>
<td> <img src="F:/image summarization/image summarization/googleDB 20 emotion vector v1.13/cc_crop_image_0620/072334.jpg", width=300, height=200> 0.5 </td>
</tr>
</table>
<html>


//Ranking.... (feature, image ranking)

FILE* file = fopen('test.html', 'w')
file.fprintf("<html>\n");
file.fprintf("<table>\n");
for(int i = 0; i< cluster_rank; i++)
{
	file.fprintf("<tr>\n");
	file.fprintf("%d\n", i+1);
	for(int j = 0; j< image_rank; j++)
	{
		file.fprintf("<td><img src=\"%s\", height=300, width=200>%f</td>", filepath, rankvalue);
	}
	file.fprintf("</tr>\n")
}

file.fprintf("</html>\n");
file.fprintf("</table>\n");
