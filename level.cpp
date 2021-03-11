//
// Created by Sergey on 04.11.2020.
//
#include "level.h"

extern float CurrentFrame;
extern int timer;

extern bool guidance;

extern sf::String who;

extern int gold;
extern int golddialog;

extern int notesroomdialog;
extern int notesroom;

extern int beardialog;
extern int bear;

extern int windowroomdialog;
extern int windowroom;

extern int sworddialog;
extern int sword;

extern int tablichkaroomdialog;
extern int tablichkaroom;

extern int mirrordialog;
extern int mirror;

extern int cabinetdialog;
extern int cabinet;

extern int tablichkakoridor;
extern int tablichkakoridordialog;

extern int skladkoridor;
extern int skladkoridordialog;

extern int Door;
extern int Doordialog;

extern int Badya;
extern int Badyadialog;

extern int ryukzak;
extern int ryukzakdialog;

extern int sundukkuxnya;
extern int sundukkuxnyadialog;

extern int brelokkuxnya;
extern int brelokkuxnyadialog;

extern int butilka;
extern int butilkadialog;

extern int sundukmasterskaya;
extern int sundukmasterskayadialog;

extern int portreti;
extern int portretidialog;

extern int lopata;
extern int lopatadialog;

extern int zapiskakamin;
extern int zapiskakamindialog ;

extern int armor;
extern int armordialog;

extern int zerno;
extern int zernodialog;


extern bool invent;
extern bool inventpickup;

extern int typeofshoes;
extern bool shoesininvent;


extern bool showarmory;



int Object::GetPropertyInt(std::string name)//���������� ����� �������� � ����� ������
{
    return atoi(properties[name].c_str());
}

float Object::GetPropertyFloat(std::string name)
{
    return strtod(properties[name].c_str(), NULL);
}

std::string Object::GetPropertyString(std::string name)//�������� ��� � ���� ������.����� �������
{
    return properties[name];
}

bool Level::LoadFromFile(std::string filename)//���������-��������� � ������� ������ ��� ������
{
    TiXmlDocument levelFile(filename.c_str());//��������� ���� � TiXmlDocument

    // ��������� XML-�����
    if (!levelFile.LoadFile())//���� �� ������� ��������� �����
    {
        std::cout << "Loading level \"" << filename << "\" failed." << std::endl;//������ ������
        return false;
    }

    // �������� � ����������� map
    TiXmlElement *map;
    map = levelFile.FirstChildElement("map");

    // ������ �����: <map version="1.0" orientation="orthogonal"
    // width="10" height="10" tilewidth="34" tileheight="34">
    width = atoi(map->Attribute("width"));//��������� �� ����� ����� �� ��������
    height = atoi(map->Attribute("height"));//�� ��������, ������� �������� ��� ������ �
    tileWidth = atoi(map->Attribute("tilewidth"));//������� ���������
    tileHeight = atoi(map->Attribute("tileheight"));

    // ����� �������� �������� � ������������� ������� �����
    TiXmlElement *tilesetElement;
    tilesetElement = map->FirstChildElement("tileset");
    firstTileID = atoi(tilesetElement->Attribute("firstgid"));

    // source - ���� �� �������� � ���������� image
    TiXmlElement *image;
    image = tilesetElement->FirstChildElement("image");
    std::string imagepath = image->Attribute("source");

    // �������� ��������� �������
    sf::Image img;

    if (!img.loadFromFile(imagepath))
    {
        std::cout << "Failed to load tile sheet." << std::endl;//���� �� ������� ��������� �������-������� ������ � �������
        return false;
    }


    img.createMaskFromColor(sf::Color(255, 255, 255));//��� ����� �����.������ ��� �����
    tilesetImage.loadFromImage(img);
    tilesetImage.setSmooth(false);//�����������

    // �������� ���������� �������� � ����� ��������
    int columns = tilesetImage.getSize().x / tileWidth;
    int rows = tilesetImage.getSize().y / tileHeight;

    // ������ �� ��������������� ����������� (TextureRect)
    std::vector<sf::Rect<int>> subRects;

    for (int y = 0; y < rows; y++)
        for (int x = 0; x < columns; x++)
        {
            sf::Rect<int> rect;

            rect.top = y * tileHeight;
            rect.height = tileHeight;
            rect.left = x * tileWidth;
            rect.width = tileWidth;

            subRects.push_back(rect);
        }

    // ������ �� ������
    TiXmlElement *layerElement;
    layerElement = map->FirstChildElement("layer");
    layers.clear();
    objects.clear();
    while (layerElement)
    {
        Layer layer;


        // ���� ������������ opacity, �� ������ ������������ ����, ����� �� ��������� �����������
        if (layerElement->Attribute("opacity") != NULL)
        {
            float opacity = strtod(layerElement->Attribute("opacity"), NULL);
            layer.opacity = 255 * opacity;
        }
        else
        {
            layer.opacity = 255;
        }

        //  ��������� <data>
        TiXmlElement *layerDataElement;
        layerDataElement = layerElement->FirstChildElement("data");

        if (layerDataElement == NULL)
        {
            std::cout << "Bad map. No layer information found." << std::endl;
        }

        //  ��������� <tile> - �������� ������ ������� ����
        TiXmlElement *tileElement;
        tileElement = layerDataElement->FirstChildElement("tile");

        if (tileElement == NULL)
        {
            std::cout << "Bad map. No tile information found." << std::endl;
            return false;
        }

        int x = 0;
        int y = 0;

        while (tileElement)
        {

            int tileGID = atoi(tileElement->Attribute("gid"));
            int subRectToUse = tileGID - firstTileID;

            // ������������� TextureRect ������� �����
            if (subRectToUse >= 0)
            {
                sf::Sprite sprite;
                sprite.setTexture(tilesetImage);
                sprite.setTextureRect(subRects[subRectToUse]);
                sprite.setPosition(x * tileWidth, y * tileHeight);

                sprite.setColor(sf::Color(255, 255, 255, layer.opacity));



                if((tileGID == 1695) && (notesroomdialog != 0)) {
                    sprite.setColor(sf::Color::Transparent);
                }
                if((tileGID == 1934) && (lopatadialog != 0)) {
                    sprite.setColor(sf::Color::Transparent);
                }
                if((tileGID == 1401) && (ryukzakdialog != 0)) {
                    sprite.setColor(sf::Color::Transparent);
                }
                if((tileGID == 1880) && (golddialog != 0)) {
                    sprite.setColor(sf::Color::Transparent);
                }
                if((tileGID == 1879) && (brelokkuxnyadialog != 0)) {
                    sprite.setColor(sf::Color::Transparent);
                }
                if((tileGID == 1649) && (zapiskakamindialog != 0)) {
                    sprite.setColor(sf::Color::Transparent);
                }


                else {
                    layer.tiles.push_back(sprite);//���������� � ���� ������� ������

                }



            }

            tileElement = tileElement->NextSiblingElement("tile");

            x++;
            if (x >= width)
            {
                x = 0;
                y++;
                if (y >= height)
                    y = 0;
            }
        }

        layers.push_back(layer);

        layerElement = layerElement->NextSiblingElement("layer");
    }

    // ������ � ���������
    TiXmlElement *objectGroupElement;

    // ���� ���� ���� ��������
    if (map->FirstChildElement("objectgroup") != NULL)
    {
        objectGroupElement = map->FirstChildElement("objectgroup");
        while (objectGroupElement)
        {
            //  ��������� <object>
            TiXmlElement *objectElement;
            objectElement = objectGroupElement->FirstChildElement("object");

            while (objectElement)
            {
                // �������� ��� ������ - ���, ���, �������, � ��
                std::string objectType;
                if (objectElement->Attribute("type") != NULL)
                {
                    objectType = objectElement->Attribute("type");
                }
                std::string objectName;
                if (objectElement->Attribute("name") != NULL)
                {
                    objectName = objectElement->Attribute("name");
                }
                int x = atoi(objectElement->Attribute("x"));
                int y = atoi(objectElement->Attribute("y"));

                int width, height;

                sf::Sprite sprite;
                sprite.setTexture(tilesetImage);
                sprite.setTextureRect(sf::Rect<int>(0, 0, 0, 0));
                sprite.setPosition(x, y);

                if (objectElement->Attribute("width") != NULL)
                {
                    width = atoi(objectElement->Attribute("width"));
                    height = atoi(objectElement->Attribute("height"));
                }
                else
                {
                    width = subRects[atoi(objectElement->Attribute("gid")) - firstTileID].width;
                    height = subRects[atoi(objectElement->Attribute("gid")) - firstTileID].height;
                    sprite.setTextureRect(subRects[atoi(objectElement->Attribute("gid")) - firstTileID]);
                }

                // ��������� �������
                Object object;
                object.name = objectName;
                object.type = objectType;
                object.sprite = sprite;

                sf::Rect <float> objectRect;
                objectRect.top = y;
                objectRect.left = x;
                objectRect.height = height;
                objectRect.width = width;
                object.rect = objectRect;

                // "����������" �������
                TiXmlElement *properties;
                properties = objectElement->FirstChildElement("properties");
                if (properties != NULL)
                {
                    TiXmlElement *prop;
                    prop = properties->FirstChildElement("property");
                    if (prop != NULL)
                    {
                        while (prop)
                        {
                            std::string propertyName = prop->Attribute("name");
                            std::string propertyValue = prop->Attribute("value");

                            object.properties[propertyName] = propertyValue;

                            prop = prop->NextSiblingElement("property");
                        }
                    }
                }


                objects.push_back(object);

                objectElement = objectElement->NextSiblingElement("object");
            }
            objectGroupElement = objectGroupElement->NextSiblingElement("objectgroup");
        }
    }
    else
    {
        std::cout << "No object layers found..." << std::endl;
    }

    return true;
}

Object Level::GetObject(std::string name)
{
    // ������ ������ ������ � �������� ������
    for (int i = 0; i < objects.size(); i++)
        if (objects[i].name == name)
            return objects[i];
}

std::vector<Object> Level::GetObjects(std::string name)
{
    // ��� ������� � �������� ������
    std::vector<Object> vec;
    for (int i = 0; i < objects.size(); i++)
        if (objects[i].name == name)
            vec.push_back(objects[i]);

    return vec;
}


std::vector<Object> Level::GetAllObjects()
{
    return objects;
};


sf::Vector2i Level::GetTileSize()
{
    return sf::Vector2i(tileWidth, tileHeight);
}

void Level::Draw(sf::RenderWindow &window)
{
    // ������ ��� ����� (������� �� ������!)
    for (int layer = 0; layer < layers.size(); layer++)
        for (int tile = 0; tile < layers[layer].tiles.size(); tile++)
            window.draw(layers[layer].tiles[tile]);

}

