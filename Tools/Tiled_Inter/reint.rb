require 'json'

def screen_to_world(x, y)
  world_dim_x = 20.0
  world_dim_y = 20.0
  window_width = 896.0
  window_height = 896.0
  worldX = ((x / window_width) - 0.5 ) * world_dim_x;
  worldY = ( 0.5 - (y / window_height) ) * world_dim_y;
  return worldX, worldY
end

def pixels_to_units(px)
  world_dim_x = 20.0
  world_dim_y = 20.0
  window_width = 896.0
  window_height = 896.0
  ratio = window_width / world_dim_x
  return px / ratio
end
file = open("with_castle.json")
json = file.read
parsed = JSON.parse(json)
squares = parsed["layers"][0]["data"]
objects = parsed["layers"][1]["data"]
castle = parsed["layers"][2]["data"]
window_h = parsed["height"]
window_w = parsed["width"]
tilt_h = parsed["tileheight"]
tilt_w = parsed["tilewidth"]
Tile = Struct.new(:name, :src, :width, :height)
tiles = Array.new
parsed["tilesets"].each do |set|
	tiles[set["firstgid"]] = Tile.new(set["name"], set["image"].gsub('../../TowerDefense/',''), set["imagewidth"], set["imageheight"])
end
f = File.new("../../TowerDefense/Config/Level/level.lua", "w")
posx = -0.5 * tilt_w
posy = 0.5 * tilt_h
squares.each_with_index do |t, index|
	if ((index % window_w) == 0) && (index != 0) then 
		posx = 0.5 * tilt_w
		posy += tilt_h
	else
		posx += tilt_w
	end
	if t != 0 then
		x, y = screen_to_world(posx, posy)
		w, h = pixels_to_units(tilt_w), pixels_to_units(tilt_h) 
		f.puts "#{tiles[t].name}_#{index} = {"
		f.puts "\tsize = {#{h}, #{w}},"
		f.puts "\tdef = '#{tiles[t].name}',"
		f.puts "\tsprite = '#{tiles[t].src}',"
		f.puts "\tlayer = 'background',"
		f.puts "\tposition = {#{x},#{y}},"
		f.puts "\ttag = 'background',"
		f.puts "}"
		if objects[index] != 0 then
			f.puts "#{tiles[objects[index]].name}_#{index} = {"
			f.puts "\tsize = {#{h}, #{w}},"
			f.puts "\tdef = '#{tiles[objects[index]].name}',"
			f.puts "\tsprite = '#{tiles[objects[index]].src}',"
			f.puts "\tlayer = 'objects',"
			f.puts "\tposition = {#{x},#{y}},"
			f.puts "\ttag = '#{tiles[objects[index]].name}',"
			f.puts "}"
		end
		if castle[index] != 0 then
			castle_h, castle_w = pixels_to_units(tiles[castle[index]].height), pixels_to_units(tiles[castle[index]].width) 
			pos_x, pos_y = screen_to_world((posx + castle_w / 2), posy)
			f.puts "#{tiles[castle[index]].name} = {"
			f.puts "\tsize = {#{castle_h}, #{castle_w}},"
			f.puts "\tdef = '#{tiles[castle[index]].name}',"
			f.puts "\tsprite = '#{tiles[castle[index]].src}',"
			f.puts "\tlayer = 'objects',"
			f.puts "\tposition = {#{pos_x},#{pos_y}},"
			f.puts "\ttag = '#{tiles[castle[index]].name}',"
			f.puts "}"
		end
	end
end

f.close

	
