#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

const unsigned char sintable[256] = {
	128,133,139,144,150,155,160,166,
	171,176,181,186,191,196,201,205,
	209,214,218,222,225,229,232,235,
	238,241,243,245,247,249,251,252,
	253,254,255,255,255,255,255,254,
	253,252,251,249,247,245,243,241,
	238,235,232,229,225,222,218,214,
	209,205,201,196,191,186,181,176,
	171,166,160,155,150,144,139,133,
	128,122,116,111,105,100,95,89,
	84,79,74,69,64,59,54,50,
	46,41,37,33,30,26,23,20,
	17,14,12,10,8,6,4,3,
	2,1,0,0,0,0,0,1,
	2,3,4,6,8,10,12,14,
	17,20,23,26,30,33,37,41,
	46,50,54,59,64,69,74,79,
	84,89,95,100,105,111,116,122 };

void PackToTiles(const vector<vector<unsigned char>>& data, vector<unsigned int>& tiles_ids, vector<vector<unsigned char>>& tiles_data, bool pack, int max_tiles_count = 255, int acceptable_error = 0)
{
	// Create tiles
	vector<vector<unsigned char>> tiles;
	unsigned int width = data[0].size() / 8 + (data[0].size() % 8 != 0 ? 1 : 0);
	unsigned int height = data.size() / 8 + (data.size() % 8 != 0 ? 1 : 0);
	tiles.resize(width * height);

	for (unsigned int y = 0; y < height; ++y)
	{
		for (unsigned int x = 0; x < width; ++x)
		{
			vector<unsigned char>& tile = tiles[y * width + x];
			tile.resize(2 * 8);

			// Pack tile
			for (unsigned int j = 0; j < 8; ++j)
			{
				for (unsigned int i = 0; i < 2; ++i)
				{
					unsigned char c0 = (y * 8 + j) < data.size() && (x * 8 + 0) < data[0].size() ? (data[y * 8 + j][x * 8 + 0] >> i & 1) : 0;
					unsigned char c1 = (y * 8 + j) < data.size() && (x * 8 + 1) < data[0].size() ? (data[y * 8 + j][x * 8 + 1] >> i & 1) : 0;
					unsigned char c2 = (y * 8 + j) < data.size() && (x * 8 + 2) < data[0].size() ? (data[y * 8 + j][x * 8 + 2] >> i & 1) : 0;
					unsigned char c3 = (y * 8 + j) < data.size() && (x * 8 + 3) < data[0].size() ? (data[y * 8 + j][x * 8 + 3] >> i & 1) : 0;
					unsigned char c4 = (y * 8 + j) < data.size() && (x * 8 + 4) < data[0].size() ? (data[y * 8 + j][x * 8 + 4] >> i & 1) : 0;
					unsigned char c5 = (y * 8 + j) < data.size() && (x * 8 + 5) < data[0].size() ? (data[y * 8 + j][x * 8 + 5] >> i & 1) : 0;
					unsigned char c6 = (y * 8 + j) < data.size() && (x * 8 + 6) < data[0].size() ? (data[y * 8 + j][x * 8 + 6] >> i & 1) : 0;
					unsigned char c7 = (y * 8 + j) < data.size() && (x * 8 + 7) < data[0].size() ? (data[y * 8 + j][x * 8 + 7] >> i & 1) : 0;
					tile[j * 2 + i] = (c0 << 7) | (c1 << 6) | (c2 << 5) | (c3 << 4) | (c4 << 3) | (c5 << 2) | (c6 << 1) | (c7 << 0);
				}
			}
		}
	}

	// Build tilemap
	bool alreadyWarned = false;
	tiles_ids.resize(width * height);
	for (unsigned int id = 0; id < tiles.size(); ++id)
	{
		bool exist = false;
		int bestTileId = 0;
		int pixelNotEqualCount = 255;

		if (pack)
		{
			for (unsigned int i = 0; i < tiles_data.size(); ++i)
			{
				int notEqualCount = 0;
				for (unsigned int j = 0; j < tiles_data[i].size(); ++j)
				{
					if (tiles[id][j] != tiles_data[i][j])
					{
						++notEqualCount;
					}
				}

				if (notEqualCount < pixelNotEqualCount)
				{
					pixelNotEqualCount = notEqualCount;
					bestTileId = i;
				}
			}

			if (pixelNotEqualCount <= acceptable_error)
			{
				tiles_ids[id] = bestTileId;
				exist = true;
			}
		}

		if (!exist)
		{
			if (tiles_data.size() == max_tiles_count)
			{
				if (!alreadyWarned)
				{
					cout << "TO MUCH TILES !\n";
					alreadyWarned = true;
				}

				tiles_ids[id] = bestTileId;
			}
			else
			{
				tiles_ids[id] = tiles_data.size();
				tiles_data.push_back(tiles[id]);
			}
		}
	}
}

void ExportTiles(const vector<unsigned int>& tiles_ids, const vector<vector<unsigned char>>& tiles_data, string name)
{
	string file_path = "../demo/resources/" + name + ".h";
	string file_data;

	file_data += "const unsigned int " + name + "_tiledata_count = " + to_string(tiles_data.size()) + ";\n";
	file_data += "const unsigned char " + name + "_tiledata[] = {";
	for (unsigned int i = 0; i < tiles_data.size(); ++i)
	{
		file_data += "\n    ";
		for (unsigned int j = 0; j < tiles_data[i].size(); ++j)
		{
			file_data += to_string(tiles_data[i][j]) + (!(i == tiles_data.size() - 1 && j == tiles_data[i].size() - 1) ? ", " : "\n");
		}
	}
	file_data += "};\n\n";

	unsigned int id = 0;
	unsigned int offset = 0;
	while (offset < tiles_ids.size())
	{
		unsigned int count = tiles_ids.size() - offset;
		if (count > 256)
			count = 256;

		file_data += "const unsigned int " + name + "_tilemap" + to_string(id) + "_count = " + to_string(count) + ";\n";
		file_data += "const unsigned char " + name + "_tilemap" + to_string(id) + "[] = { \n";
		for (unsigned int i = offset; i < offset + count; ++i)
		{
			file_data += to_string(tiles_ids[i]) + (i < offset + count - 1 ? ", " : "\n");
		}
		file_data += "};\n\n";

		++id;
		offset += count;
	}

	ofstream output(file_path);
	output << file_data;
}

void ExportSquaresZoom(string name)
{
	vector<vector<unsigned char>> data;

	for (int y = 0; y < 170; ++y) // 160+4+.. (remove artifacts)
	{
		int square_size = 16 + y / 4;
		vector<unsigned char> line;
		line.reserve(32 * 8);
		for (int x = 0; x < 32 * 8; ++x)
		{
			unsigned char color = ((x / square_size) % 2) * 2;
			if (color == 0)
			{
				color = (((x + square_size / 8) / square_size) % 2) * 3;

				if (color == 0)
				{
					int fx = (x + x * (y / 4)) / (1 + (y / 6) * 16);
					int col = (abs(fx + (y & 1)) / 10) % 3;

					if (y > 80 && x >= 9 * 22)
						col = (y & 1) + 2;
					else if (y > 80 && x >= 8 * 22)
						col = 2;
					else if (y > 80 && x >= 7 * 22)
						col = (y & 1) + 1;

					color = col;
				}

			}
			else
			{
				color = 3;

				int fx = (x + x * (y / 16)) / (1 + (y / 6) * 16);
				int col = (abs(fx + (y & 1)) / 10) % 3;

				color = 3 - col / 2;
			}

			line.push_back(color);
		}
		data.push_back(line);
	}

	vector<unsigned int> tiles_ids;
	vector<vector<unsigned char>> tiles_data;
	PackToTiles(data, tiles_ids, tiles_data, true, 180, 0);
	ExportTiles(tiles_ids, tiles_data, name);
}

void ExportSquaresZoomPrecalc(string name)
{
	string file_path = "../demo/resources/" + name + ".h";
	string file_data;

	file_data += "const unsigned char " + name + "[][41] = {\n";  //200, 41 144+16+40

	for (unsigned char y = 0; y < 200; ++y)
	{
		file_data += "    { ";

		for (unsigned char x = 0; x < 41; ++x)
		{
			unsigned char h = y;
			if (h >= 200) // 144+16+40
				h = 200;

			unsigned char value = ((h / (16 + x)) & 1) * (16 + x);

			file_data += to_string(value);

			if (x < 40)
			{
				file_data += ", ";
			}
		}

		file_data += "}";

		if (y < 199)
		{
			file_data += ",\n";
		}
	}

	file_data += "\n};";

	ofstream output(file_path);
	output << file_data;
}

void ExportSquaresRacePrecalc(string name)
{
	string file_path = "../demo/resources/" + name + ".h";
	string file_data;

	const unsigned char race_loop = 64;
	const unsigned char race_divide = 12;
#define race_i_mul 12/8
	unsigned char squares_precalc_x[72][race_loop];
	unsigned char squares_precalc_y[72][race_loop];

	for (unsigned char i = 0; i < race_loop; ++i)
	{
		unsigned char old_size = ((i * race_i_mul) * (i * race_i_mul)) / race_divide;
		unsigned char s = ((i * race_i_mul) / race_divide) & 1;

		for (unsigned char j = 0; j < 72; ++j)
		{
			unsigned char square_size = j * 2 / 3 + 16;
			unsigned char p = (j + (i * race_i_mul)) / race_divide;
			unsigned char psquare_size = p * p;

			if (psquare_size != old_size)
			{
				old_size = psquare_size;
				s = !s;
			}

			unsigned char add = 0;
			if (s != 0) add = square_size;

			unsigned char sin = j * sintable[((i - 16) * 3) % 256] / 64;

			squares_precalc_x[j][i] = (add + j + sin) % (square_size * 2);
			squares_precalc_y[j][i] = (square_size - 16) * 4;
		}
	}

	file_data += "#define race_loop " + to_string(race_loop - 16) + "\n";
	file_data += "#define race_divide " + to_string(race_divide) + "\n";
	file_data += "#define race_i_mul 12/8\n";
	file_data += "const UINT8 squares_precalc_x[][" + to_string(race_loop - 16) + "] = {\n";

	for (unsigned char j = 0; j < 72; ++j)
	{
		file_data += "    { ";

		for (unsigned char i = 16; i < race_loop; ++i)
		{
			file_data += to_string(squares_precalc_x[j][i]);
			if (i < race_loop - 1)
				file_data += ", ";
		}

		file_data += " }";
		if (j < 71)
			file_data += ",";
		file_data += "\n";
	}
	file_data += "\n};";

	file_data += "const UINT8 squares_precalc_y[][" + to_string(race_loop - 16) + "] = {\n";

	for (unsigned char j = 0; j < 72; ++j)
	{
		file_data += "    { ";

		for (unsigned char i = 16; i < race_loop; ++i)
		{
			file_data += to_string(squares_precalc_y[j][i]);
			if (i < race_loop - 1)
				file_data += ", ";
		}

		file_data += " }";
		if (j < 71)
			file_data += ",";
		file_data += "\n";
	}
	file_data += "\n};";

	ofstream output(file_path);
	output << file_data;
}

void ExportVBarrels(string name)
{
	vector<vector<unsigned char>> data;

	for (int y = 0; y < 170; ++y) // 160+4+.. (remove artifacts)
	{
		int offset = y / 4;
		vector<unsigned char> line;
		line.reserve(20 * 8);
		for (int x = 0; x < 20 * 8; ++x)
		{
			unsigned char color = 0;

			if (x >= 30 && x < 70)
			{
				if (x < y) color = 2;
				else color = 1;
				if (x >= 30 + (offset / 2 + 5) % 40)
					color = 3 - (y < 80 ? x % 2 : 0);
			}

			int p = (int)(20 + sin(3.14156f * (y / 4) / 40.0f) * 110.0f);
			if (x >= p && x < p + 40 && y % 2 == 0)
			{
				color = 1;
				if (x >= p + offset)
					color = 1 + x % 2;
			}

			if (x >= 110 && x < 130)
			{
				if (x % 4 > 1)
				{
					color = x % 4;
					if (x >= 110 + (offset / 2 + 10) % 21)
						color = 2 + x % 6;
				}
			}

			line.push_back(color);
		}
		data.push_back(line);
	}

	vector<unsigned int> tiles_ids;
	vector<vector<unsigned char>> tiles_data;
	PackToTiles(data, tiles_ids, tiles_data, true);
	ExportTiles(tiles_ids, tiles_data, name);
}

void ExportFont(string name)
{
	vector<vector<unsigned char>> src_data;
	vector<vector<unsigned char>> data;
	string src = "../images/" + name + "_font.bmp";
	string dst = "bitmap_" + name + "_font";

	printf((src + " font\n").c_str());

	FILE* file;
	fopen_s(&file, src.c_str(), "rb");
	fseek(file, 18, SEEK_SET);
	int w, h;
	fread(&w, 4, 1, file);
	fread(&h, 4, 1, file);

	fseek(file, 0x000A, SEEK_SET);
	int offset;
	fread(&offset, 4, 1, file);
	fseek(file, offset, SEEK_SET);

	src_data.resize(h);
	for (int y = h - 1; y >= 0; --y)
	{
		src_data[y].resize(w);
		for (int x = 0; x < w / 2; ++x)
		{
			unsigned char pixel;
			fread(&pixel, 1, 1, file);

			unsigned char left = pixel >> 4;
			unsigned char right = pixel & 15;

			if (left > 3 || right > 3)
			{
				printf("INVALID BITMAP !!!\n");
				break;
			}
			src_data[y][x * 2 + 0] = 3 - left;
			src_data[y][x * 2 + 1] = 3 - right;
		}
	}

	data.resize(h * 5);
	for (int step = 0; step < 5; ++step)
	{
		for (int glyph = 0; glyph < 25; ++glyph)
		{
			for (int y = 0; y < 8; ++y)
			{
				if (data[step * 8 + y].size() != w)
				{
					data[step * 8 + y].resize(w);
				}

				for (int x = 0; x < 8; ++x)
				{
					unsigned char v = src_data[y][glyph * 8 + x];

					if (step == 1 && (y % 5 == 0 || x % 5 == 0))
					{
						v = 0;
					}
					else if (step == 2 && (y % 4 == 0 || x % 4 == 0))
					{
						v = 0;
					}
					else if (step == 3 && (y % 3 == 0 || x % 3 == 0))
					{
						v = 0;
					}
					else if (step == 4 && (y % 2 == 0 || x % 2 == 0))
					{
						v = 0;
					}

					data[step * 8 + y][glyph * 8 + x] = v;
				}
			}
		}
	}

	fclose(file);

	vector<unsigned int> tiles_ids;
	vector<vector<unsigned char>> tiles_data;
	PackToTiles(data, tiles_ids, tiles_data, false);
	ExportTiles(tiles_ids, tiles_data, dst);
}

void ExportScroller(string name)
{
	vector<vector<unsigned char>> src_data;
	vector<vector<unsigned char>> data;
	string src = "../images/" + name + ".txt";
	string dst = "resources/bitmap_" + name + ".h";

	printf((src + "\n").c_str());

	string file_data;
	file_data += "const unsigned char " + name + "_data[] = {\n";

	std::ifstream ifile(src);
	std::string str;
	int count = 0;
	while (std::getline(ifile, str))
	{
		int len = str.length();
		file_data += to_string(len) + ", ";
		for (int i = 0; i < len; ++i)
		{
			unsigned char c = str[i] - 'a';
			if (c < 0 || c >= 26 - 1) // no Z
			{
				c = 0;
			}
			file_data += to_string(c) + ", ";
		}
		file_data += "\n";
		++count;
	}

	file_data += "0};\n";
	file_data += "const unsigned int " + name + "_data_count = " + to_string(count) + ";\n";
	ofstream output(dst);
	output << file_data;
}

void ExportScrollerCube()
{
	vector<vector<unsigned char>> bkg_data;
	vector<vector<unsigned char>> data;
	string bkgSrc = "../images/alien_girl_cube_bkg.bmp";
	string src = "../data/cube.bytes";
	string dst = "bitmap_scroller_cube";
	int size = 32;
	int angle = 24;
	int framesCount = (360 - angle) / angle;

	printf((src + "\n").c_str());

	FILE* file;

	fopen_s(&file, bkgSrc.c_str(), "rb");
	fseek(file, 18, SEEK_SET);
	int w, h;
	fread(&w, 4, 1, file);
	fread(&h, 4, 1, file);

	fseek(file, 0x000A, SEEK_SET);
	int offset;
	fread(&offset, 4, 1, file);
	fseek(file, offset, SEEK_SET);

	bkg_data.resize(h);
	for (int y = h - 1; y >= 0; --y)
	{
		bkg_data[y].resize(w);
		for (int x = 0; x < w / 2; ++x)
		{
			unsigned char pixel;
			fread(&pixel, 1, 1, file);

			unsigned char left = pixel >> 4;
			unsigned char right = pixel & 15;

			if (left > 3 || right > 3)
			{
				printf("INVALID BITMAP !!!\n");
				break;
			}
			bkg_data[y][x * 2 + 0] = 3 - left;
			bkg_data[y][x * 2 + 1] = 3 - right;
		}
	}
	fclose(file);

	fopen_s(&file, src.c_str(), "rb");

	data.resize(size * framesCount);
	for (int y = 0; y < (int)data.size(); ++y)
	{
		data[y].resize(size);
	}

	for (int f = 0; f < framesCount; ++f)
	{
		int clear = 0;
		if (f < 4) clear = 8 - f * 2;
		else if (f >= framesCount - 3) clear = 2 + (framesCount - 3) * 2;

		for (int y = size - 1; y >= 0; --y)
		{
			for (int x = 0; x < size; ++x)
			{
				unsigned char pixel;
				fread(&pixel, 1, 1, file);

				pixel = 3 - pixel * 3 / 255;

				if (clear != 0 && (clear == 8 || x % clear != 0 || y % clear != 0))
					pixel = 3;

				if (pixel == 3) pixel = bkg_data[y][x];

				data[y + f * size][x] = pixel;
			}
		}
	}
	fclose(file);

	vector<unsigned int> tiles_ids;
	vector<vector<unsigned char>> tiles_data;
	PackToTiles(data, tiles_ids, tiles_data, true, 255, 2);
	ExportTiles(tiles_ids, tiles_data, dst);
}

void ExportTorus()
{
	vector<vector<unsigned char>> data;
	string src = "../data/torus.bytes";
	string dst = "bitmap_torus";
	int size = 16;
	int angle = 20;
	int framesCount = (360 - angle) / angle;

	printf((src + "\n").c_str());

	FILE* file;

	fopen_s(&file, src.c_str(), "rb");

	data.resize(size);
	for (int y = 0; y < (int)data.size(); ++y)
	{
		data[y].resize(size * framesCount);
	}

	for (int y = 0; y < size; ++y)
	{
		for (int x = 0; x < size * framesCount; ++x)
		{
			unsigned char pixel;
			fread(&pixel, 1, 1, file);

			pixel = pixel * 3 / 255;
			if (pixel > 0) pixel = 4 - pixel;

			data[y][x] = pixel;
		}
	}
	fclose(file);

	vector<unsigned int> tiles_ids;
	vector<vector<unsigned char>> tiles_data;
	PackToTiles(data, tiles_ids, tiles_data, false, 255, 0);
	ExportTiles(tiles_ids, tiles_data, dst);
}

void ExportTitleTiles(const vector<unsigned int>& tiles_ids, const vector<vector<unsigned char>>& tiles_data, string name)
{
	string file_path = "../demo/resources/" + name + ".h";
	string file_data;

	file_data += "const unsigned int " + name + "_tiledata_count = " + to_string(tiles_data.size()) + ";\n";
	file_data += "const unsigned char " + name + "_tiledata[] = {";
	for (unsigned int i = 0; i < tiles_data.size(); ++i)
	{
		file_data += "\n    ";
		for (unsigned int j = 0; j < tiles_data[i].size(); ++j)
		{
			file_data += to_string(tiles_data[i][j]) + (!(i == tiles_data.size() - 1 && j == tiles_data[i].size() - 1) ? ", " : "\n");
		}
	}
	file_data += "};\n\n";

	unsigned int id = 0;
	unsigned int offset = 0;
	unsigned int max = 256;
	while (offset < tiles_ids.size())
	{
		unsigned int count = tiles_ids.size() - offset;
		if (count > max)
			count = max;

		if (max == 256) max = 104;
		else max = 256;

		file_data += "const unsigned int " + name + "_tilemap" + to_string(id) + "_count = " + to_string(count) + ";\n";
		file_data += "const unsigned char " + name + "_tilemap" + to_string(id) + "[] = { \n";
		for (unsigned int i = offset; i < offset + count; ++i)
		{
			file_data += to_string(tiles_ids[i]) + (i < offset + count - 1 ? ", " : "\n");
		}
		file_data += "};\n\n";

		++id;
		offset += count;
	}

	ofstream output(file_path);
	output << file_data;
}

void ExportTitle(string name)
{
	vector<vector<unsigned char>> data;
	string src = "../images/" + name + ".bmp";
	string dst = "bitmap_" + name;

	printf((src + "\n").c_str());

	FILE* file;
	fopen_s(&file, src.c_str(), "rb");
	fseek(file, 18, SEEK_SET);
	int w, h;
	fread(&w, 4, 1, file);
	fread(&h, 4, 1, file);

	fseek(file, 0x000A, SEEK_SET);
	int offset;
	fread(&offset, 4, 1, file);
	fseek(file, offset, SEEK_SET);

	data.resize(h * 8);
	for (int y = h - 1; y >= 0; --y)
	{
		data[y].resize(w);
		for (int x = 0; x < w / 2; ++x)
		{
			unsigned char pixel;
			fread(&pixel, 1, 1, file);

			unsigned char left = pixel >> 4;
			unsigned char right = pixel & 15;

			if (left > 3 || right > 3)
			{
				printf("INVALID BITMAP !!!\n");
				break;
			}
			data[y][x * 2 + 0] = 3 - left;
			data[y][x * 2 + 1] = 3 - right;
		}
	}
	fclose(file);

	for (int s = 1; s < 8; ++s)
	{
		for (int y = 0; y < h; ++y)
		{
			data[y + s * h].resize(w);

			for (int x = 0; x < w; ++x)
			{
				float zoom = 1.0f / (1.0f + s * 0.4f);
				int ux = (int)((x - (w - 1.0f) / 2.0f) * zoom + (w - 1.0f) / 2.0f);
				int uy = (int)((y - (h - 1.0f) / 2.0f) * zoom + (h - 1.0f) / 2.0f);

				if (ux >= w || ux < 0 || ux >= h || uy < 0)
				{
					data[y + s * h][x] = 3;
				}
				else
				{
					data[y + s * h][x] = data[uy][ux];
				}
			}
		}
	}

	vector<unsigned int> tiles_ids;
	vector<vector<unsigned char>> tiles_data;
	PackToTiles(data, tiles_ids, tiles_data, true, 255, 0);
	ExportTitleTiles(tiles_ids, tiles_data, dst);
}

static std::vector<unsigned char> ReadAllBytes(string filename)
{
	std::ifstream ifs(filename, std::ios::binary | std::ios::ate);
	std::ifstream::pos_type pos = ifs.tellg();

	if (pos == 0) {
		return std::vector<unsigned char>{};
	}

	std::vector<unsigned char> result((unsigned int)pos);
	std::vector<char> tmp((unsigned int)pos);

	ifs.seekg(0, std::ios::beg);
	ifs.read(&tmp[0], pos);

	memcpy(&result[0], &tmp[0], result.size());

	return result;
}

void ExportAnimation(string name)
{
	string src = "../data/" + name + ".bytes";
	std::vector<unsigned char> data = ReadAllBytes(src);

	int framesCount = data[0];
	unsigned char* tilesData = &data[0] + (20 * 18) * framesCount + 1;
	int tilesCount = *tilesData;

	string file_data;
	string file_path = "../demo/resources/" + name + "_animation.h";
	file_data += "const unsigned int " + name + "_tiledata_count = " + to_string(tilesCount) + ";\n";
	file_data += "const unsigned char " + name + "_tiledata[] = {";

	for (int t = 0; t < tilesCount; ++t)
	{
		file_data += "\n    ";

		unsigned char p0 = *(tilesData + 1 + t * 4);
		unsigned char p1 = *(tilesData + 1 + t * 4 + 1);
		unsigned char p2 = *(tilesData + 1 + t * 4 + 2);
		unsigned char p3 = *(tilesData + 1 + t * 4 + 3);

		unsigned char tile[8 * 8];

		for (int y = 0; y < 8; ++y)
		{
			for (int x = 0; x < 8; ++x)
			{
				unsigned char v;
				if (x < 4)
				{
					v = y < 4 ? p0 : p2;
				}
				else
				{
					v = y < 4 ? p1 : p3;
				}

				if (x == 2) 
				{
					v = y < 4 ? p1 : p3;
				}

				if (y == 5)
				{
					v = x < 4 ? p0 : p1;
				}

				if (x == 5)
				{
					v = y < 4 ? p0 : p2;
				}
				
				if (y == 2)
				{
					v = x < 4 ? p2 : p3;
				}

				tile[y * 8 + x] = v;
			}
		}

		// Pack tile
		for (unsigned int j = 0; j < 8; ++j)
		{
			for (unsigned int i = 0; i < 2; ++i)
			{
				unsigned char c0 = tile[j * 8 + 0] >> i & 1;
				unsigned char c1 = tile[j * 8 + 1] >> i & 1;
				unsigned char c2 = tile[j * 8 + 2] >> i & 1;
				unsigned char c3 = tile[j * 8 + 3] >> i & 1;
				unsigned char c4 = tile[j * 8 + 4] >> i & 1;
				unsigned char c5 = tile[j * 8 + 5] >> i & 1;
				unsigned char c6 = tile[j * 8 + 6] >> i & 1;
				unsigned char c7 = tile[j * 8 + 7] >> i & 1;
				unsigned char p = (c0 << 7) | (c1 << 6) | (c2 << 5) | (c3 << 4) | (c4 << 3) | (c5 << 2) | (c6 << 1) | (c7 << 0);
				file_data += to_string(p) + ", ";
			}
		}
	}

	file_data += "0};\n\n";

	file_data += "const unsigned int " + name + "_frames_count = " + to_string(framesCount) + ";\n";
	file_data += "const unsigned char " + name + "_frames[] = {";

	for (int i = 0; i < framesCount; ++i)
	{
		file_data += "\n    ";

		for (int j = 0; j < 20 * 18; ++j)
		{
			file_data += to_string(data[i * 20 * 18 + j + 1]) + ", ";
		}
	}

	file_data += "\n};\n";
	file_data += "const unsigned char* " + name + "_frames_end = "+name + "_frames + " + to_string(framesCount * 20 * 18) + ";\n";

	ofstream output(file_path);
	output << file_data;
}

void ExportVideo(string name)
{
	string src = "../data/" + name + ".bytes";
	std::vector<unsigned char> data = ReadAllBytes(src);

	int framesCount = data[0];
	
	string file_data;
	string file_path = "../demo/resources/" + name + ".h";
	
	file_data += "const unsigned int " + name + "_frames_count = " + to_string(framesCount) + ";\n";
	file_data += "const unsigned char " + name + "_frames[] = {";

	for (int i = 0; i < framesCount; ++i)
	{
		file_data += "\n    ";

		for (int j = 0; j < 20 * 18; ++j)
		{
			file_data += to_string(data[i * 20 * 18 + j + 1]) + ", ";
		}
	}

	file_data += "\n};\n";
	file_data += "const unsigned char* " + name + "_frames_end = " + name + "_frames + " + to_string(framesCount * 20 * 18) + ";\n";

	ofstream output(file_path);
	output << file_data;
}

void ExportBitmap(string name, bool pack = true, int max_tiles_count = 255, int acceptable_error = 0)
{
	vector<vector<unsigned char>> data;
	string src = "../images/" + name + ".bmp";
	string dst = "bitmap_" + name;

	printf((src + "\n").c_str());

	FILE* file;
	fopen_s(&file, src.c_str(), "rb");
	fseek(file, 18, SEEK_SET);
	int w, h;
	fread(&w, 4, 1, file);
	fread(&h, 4, 1, file);

	fseek(file, 0x000A, SEEK_SET);
	int offset;
	fread(&offset, 4, 1, file);
	fseek(file, offset, SEEK_SET);

	data.resize(h);
	for (int y = h - 1; y >= 0; --y)
	{
		data[y].resize(w);
		for (int x = 0; x < w / 2; ++x)
		{
			unsigned char pixel;
			fread(&pixel, 1, 1, file);

			unsigned char left = pixel >> 4;
			unsigned char right = pixel & 15;

			if (left > 3 || right > 3)
			{
				printf("INVALID BITMAP !!!\n");
				break;
			}
			data[y][x * 2 + 0] = 3 - left;
			data[y][x * 2 + 1] = 3 - right;
		}
	}

	fclose(file);

	vector<unsigned int> tiles_ids;
	vector<vector<unsigned char>> tiles_data;
	PackToTiles(data, tiles_ids, tiles_data, pack, max_tiles_count, acceptable_error);
	ExportTiles(tiles_ids, tiles_data, dst);
}

int main()
{
	printf("Exporting data...\n");

	ExportSquaresZoom("squares_zoom");
	ExportSquaresZoomPrecalc("squares_zoom_precalc");
	ExportSquaresZoom("squares_race");
	ExportSquaresRacePrecalc("squares_race_precalc");
	ExportVBarrels("vbarrels");

	printf("Exporting bitmaps...\n");

	ExportBitmap("sega");
	ExportBitmap("fire", false);
	ExportBitmap("fire_sprites", false);
	ExportBitmap("axelay_sky");
	ExportBitmap("axelay_overlay");
	ExportBitmap("axelay_sprites", false);
	ExportBitmap("sprites_physics", false);
	ExportBitmap("sprites_physics_bkg");
	ExportBitmap("rain_bkg");
	ExportBitmap("rain_sprites", false);
	ExportBitmap("credits");
	ExportBitmap("credits_font", false);
	ExportBitmap("vbarrels_wnd");
	ExportBitmap("race_bkg");
	ExportBitmap("kiss", true, 205, 2);
	ExportBitmap("kiss_window");
	ExportBitmap("funky_girl", true, 207, 2);
	ExportBitmap("funky_girl_window");
	ExportBitmap("alien_girl");
	ExportBitmap("alien_girl_full");
	ExportBitmap("senses", true, 255, 0);
	ExportBitmap("logo");
	ExportFont("scroller");
	ExportScroller("scroller");
	ExportScrollerCube();
	ExportBitmap("title_full");
	ExportTitle("title");
	ExportAnimation("tunnel");
	ExportBitmap("cube_video", false);
	ExportVideo("cube_video");
	ExportBitmap("tunnel_video", false);
	ExportVideo("tunnel_video");
	ExportTorus();

	printf("done.\n");
}
