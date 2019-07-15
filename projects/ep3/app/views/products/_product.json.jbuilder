json.extract! product, :id, :nome, :tipo, :estado, :descricao, :doador, :created_at, :updated_at
json.url product_url(product, format: :json)
