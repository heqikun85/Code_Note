# CI/CD

项目开发过程中，经常会将新代码存入代码仓库，并且和旧代码合并。
为了确保新代码和旧代码合并后的正确性，通常会进行一次测试和部署。
为了解决这个问题，就要建立自动化的集成流程，提高工作效率
代码提交到Git或SVN后，自动触发编译，单元测试，部署等操作。这个过程称为持续集成 -- CI，Continuous Integration
代码一旦通过所有测试，就会自动部署到生产环境中，无需人为干预。称为持续部署 -- CD，Continuous Deployment

# Docker

Docker是一个容器，用来模拟某种环境的。

### 命令

* docker run -d \
  创建一个容器, 让容器在后台运行
* --name mysql \
  给容器创建一个名字，必须是唯一
* -p 3306:3306
  设置端口映射，可以通过主机的ip地址+映射端口，从外部访问docker容器
* -e key=value
* -e MYSOL ROOT PASSWORD=123
  设置环境变量，这个环境变量由镜像决定要如何配置，需要查看镜像说明文档
* mysql 
  启动的镜像名

### 常用命令

docker pull：下载镜像
docker images：查看已下载镜像
docker rmi：删除镜像

自定义镜像：创建一个 DockerFile的文件，然后通过docker build来完成构建，自定义构建，打包。
docker save：保存自定义镜像
docker load：解包自定义镜像
docker push：通过云上传自定义镜像（需要在同一环境下）
docker stop / start：停止/开始容器的进程，我们不需要每次都用docker run去创建新容器
docker ps：查看容器状态
docker rm：删除容器
docker logs：查看容易运行日志
docker exec：执行容器命令

--help 通用帮助命令

