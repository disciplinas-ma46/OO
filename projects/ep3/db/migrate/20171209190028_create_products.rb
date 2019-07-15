class CreateProducts < ActiveRecord::Migration[5.1]
  def change
    create_table :products do |t|
      t.string :nome
      t.string :tipo
      t.string :estado
      t.text :descricao
      t.string :doador

      t.timestamps
    end
  end
end
