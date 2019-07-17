class CreateMeusItens < ActiveRecord::Migration[5.1]
  def change
    create_table :meus_itens do |t|

      t.timestamps
    end
  end
end
