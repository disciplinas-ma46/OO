class CreateMeusProdutos < ActiveRecord::Migration[5.1]
  def change
    create_table :meus_produtos do |t|

      t.timestamps
    end
  end
end
